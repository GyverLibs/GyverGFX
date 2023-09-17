#pragma once
#include <Arduino.h>

// движок бегущей строки для GyverGFX

#include "GyverGFX.h"

#define RG_IDLE 0
#define RG_MOVE 1
#define RG_FINISH 2

class RunningGFX {
   public:
    RunningGFX(GyverGFX* gfx) : _gfx(gfx) {
        _x0 = _y = 0;
        _x1 = _gfx->width();
    }

    // установить текст const char*
    void setText(const char* str, uint8_t scale = 1) {
        _str = str;
        _scale = scale;
        _p = 0;
        _len = _gfx->strlen_fix(_str) * 6 * scale;
    }

    // установить текст String
    void setText(String& str, uint8_t scale = 1) {
        setText(str.c_str());
    }

    // установить текст из PROGMEM (глобальный)
    void setText_P(PGM_P str, uint8_t scale = 1) {
        _str = str;
        _scale = scale;
        _p = 1;
        _len = _gfx->strlen_fix_P(_str) * 6 * scale;
    }

    // установить окно (x0, x1, y)
    void setWindow(int16_t x0, int16_t x1, int16_t y) {
        _x0 = x0;
        _x1 = x1;
        _y = y;
    }

    // установить скорость (пикселей в секунду)
    void setSpeed(uint16_t pixPerSec) {
        if (!pixPerSec) pixPerSec = 1;
        _prd = 1000 / pixPerSec;
    }

    // запустить бегущую строку с начала
    void start() {
        _pos = _x1 + 1;
        resume();
    }

    // остановить бегущую строку
    void stop() {
        _tmr = 0;
    }

    // продолжить движение с момента остановки
    void resume() {
        _tmr = (uint16_t)millis();
        if (!_tmr) _tmr = 1;
    }

    // тикер. Вернёт 0 в холостом, 1 при новом шаге, 2 при завершении движения
    uint8_t tick() {
        if (_tmr && (uint16_t)((uint16_t)millis() - _tmr) >= _prd) {
            resume();
            _gfx->setScale(_scale);
            _gfx->setTextBound(_x0, _x1);
            _gfx->setCursor(_x0 + _pos, _y);
            if (_p) _gfx->print((const __FlashStringHelper*)_str);
            else _gfx->print(_str);
            _gfx->update();
            if (--_pos <= -_len) {
                start();
                return RG_FINISH;
            }
            return RG_MOVE;
        }
        return RG_IDLE;
    }

   private:
    GyverGFX* _gfx;
    const char* _str = nullptr;
    uint16_t _tmr = 0, _prd = 50;
    int16_t _len = 0;
    int16_t _x0, _x1, _y;
    int16_t _pos = 0;
    uint8_t _scale = 1;
    bool _p = 0;
};