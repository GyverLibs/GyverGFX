[![Foo](https://img.shields.io/badge/Version-1.3-brightgreen.svg?style=flat-square)](#versions)
[![Foo](https://img.shields.io/badge/Website-AlexGyver.ru-blue.svg?style=flat-square)](https://alexgyver.ru/)
[![Foo](https://img.shields.io/badge/%E2%82%BD$%E2%82%AC%20%D0%9D%D0%B0%20%D0%BF%D0%B8%D0%B2%D0%BE-%D1%81%20%D1%80%D1%8B%D0%B1%D0%BA%D0%BE%D0%B9-orange.svg?style=flat-square)](https://alexgyver.ru/support_alex/)

[![Foo](https://img.shields.io/badge/README-ENGLISH-brightgreen.svg?style=for-the-badge)](https://github-com.translate.goog/GyverLibs/GyverGFX?_x_tr_sl=ru&_x_tr_tl=en)

# GyverGFX
Лёгкая библиотека двухмерной графики для дисплеев и матриц
- Точки
- Линии
- Прямоугольники
- Скруглённые прямоугольники
- Круги
- Кривая Безье
- Битмап
- Вывод текста (русский, английский) нескольких размеров

### Совместимость
Совместима со всеми Arduino платформами (используются Arduino-функции)

## Содержание
- [Установка](#install)
- [Инициализация](#init)
- [Использование](#usage)
- [Пример](#example)
- [Версии](#versions)
- [Баги и обратная связь](#feedback)

<a id="install"></a>
## Установка
- Библиотеку можно найти по названию **GyverGFX** и установить через менеджер библиотек в:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Скачать библиотеку](https://github.com/GyverLibs/GyverGFX/archive/refs/heads/main.zip) .zip архивом для ручной установки:
    - Распаковать и положить в *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Распаковать и положить в *C:\Program Files\Arduino\libraries* (Windows x32)
    - Распаковать и положить в *Документы/Arduino/libraries/*
    - (Arduino IDE) автоматическая установка из .zip: *Скетч/Подключить библиотеку/Добавить .ZIP библиотеку…* и указать скачанный архив
- Читай более подробную инструкцию по установке библиотек [здесь](https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)

<a id="init"></a>
## Инициализация
```cpp
GyverGFX();
GyverGFX(int x, int y); // с указанием размеров "экрана"
```

<a id="usage"></a>
## Использование
```cpp
// fill:
// GFX_CLEAR - очистить
// GFX_FILL - залить фигуру
// GFX_STROKE - обвести фигуру

void size(int x, int y);                                            // установить размер
virtual void dot(int x, int y, uint8_t fill = 1);                   // точка
void fill(uint8_t fill = 1);                                        // залить
void clear();                                                       // очистить
void fastLineH(int y, int x0, int x1, uint8_t fill = 1);            // вертикальная линия
void fastLineV(int x, int y0, int y1, uint8_t fill = 1);            // горизонтальная линия
void line(int x0, int y0, int x1, int y1, uint8_t fill = 1);        // линия
void rect(int x0, int y0, int x1, int y1, uint8_t fill = 1);        // прямоугольник
void roundRect(int x0, int y0, int x1, int y1, uint8_t fill = 1);   // скруглённый прямоугольник
void circle(int x, int y, int radius, uint8_t fill = 1);            // окружность
void bezier(uint8_t* arr, uint8_t size, uint8_t dense, uint8_t fill = 1);   // кривая Безье
void bezier16(int* arr, uint8_t size, uint8_t dense, uint8_t fill = 1);     // кривая Безье 16 бит. fill - GFX_CLEAR/GFX_FILL/GFX_STROKE
void drawBitmap(int x, int y, const uint8_t *frame, int width, int height, uint8_t invert = 0, byte mode = 0);  // битмап

void setCursor(int x, int y);           // установить курсор
void setScale(uint8_t scale);           // масштаб текста
void invertText(bool inv);              // инвертировать текст
void autoPrintln(bool mode);            // автоматический перенос строки
void textDisplayMode(bool mode);        // режим вывода текста GFX_ADD/GFX_REPLACE
```

<a id="example"></a>
## Пример
```cpp
// пример наследования в класс
class MAX7219 : public GyverGFX {
public:
    MAX7219() : GyverGFX(width * 8, height * 8) {
        begin();
    }
```

<a id="versions"></a>
## Версии
- v1.0
- v1.1 - оптимизация памяти
- v1.2 - небольшая оптимизация
- v1.3 - добавил фичи

<a id="feedback"></a>
## Баги и обратная связь
При нахождении багов создавайте **Issue**, а лучше сразу пишите на почту [alex@alexgyver.ru](mailto:alex@alexgyver.ru)  
Библиотека открыта для доработки и ваших **Pull Request**'ов!