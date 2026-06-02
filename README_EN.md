This is an automatic translation and may be incorrect in some places. See the source README and examples for authoritative information.

[![latest](https://img.shields.io/github/v/release/GyverLibs/GyverGFX.svg?color=brightgreen)](https://github.com/GyverLibs/GyverGFX/releases/latest/download/GyverGFX.zip)
[![PIO](https://badges.registry.platformio.org/packages/gyverlibs/library/GyverGFX.svg)](https://registry.platformio.org/libraries/gyverlibs/GyverGFX)
[![Foo](https://img.shields.io/badge/Website-AlexGyver.ru-blue.svg?style=flat-square)](https://alexgyver.ru/)
[![Foo](https://img.shields.io/badge/%E2%82%BD%24%E2%82%AC%20%D0%9F%D0%BE%D0%B4%D0%B4%D0%B5%D1%80%D0%B6%D0%B0%D1%82%D1%8C-%D0%B0%D0%B2%D1%82%D0%BE%D1%80%D0%B0-orange.svg?style=flat-square)](https://alexgyver.ru/support_alex/)
[![Foo](https://img.shields.io/badge/README-ENGLISH-blueviolet.svg?style=flat-square)](https://github-com.translate.goog/GyverLibs/GyverGFX?_x_tr_sl=ru&_x_tr_tl=en)  

[![Foo](https://img.shields.io/badge/ПОДПИСАТЬСЯ-НА%20ОБНОВЛЕНИЯ-brightgreen.svg?style=social&logo=telegram&color=blue)](https://t.me/GyverLibs)

# GyverGFX
Two-dimensional graphics engine for displays and matrices
- Point
- Lines
- Rectangles
- Circle
- Bezier's curve
- Bitmap
- Text output (Russian, English) of several sizes
- Stitched 155 icons
- Running line

### Compatibility
Compatible with all Arduino platforms (Arduino features are used)

## Contents
- [Installation](#install)
- [Use of use](#usage)
- [Example](#example)
- [Versions](#versions)
- [Bugs and feedback](#feedback)

<a id="install"></a>
## Installation
- The library can be found under the name **GyverGFX** and installed through the library manager in:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Download the library](https://github.com/GyverLibs/GyverGFX/archive/refs/heads/main.zip).zip archive for manual installation:
    - Unpack and put in *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Unpack and put in *C:\Program Files\Arduino\libraries* (Windows x32)
    - Unpack and put in *Documents/Arduino/libraries/ *
    - (Arduino IDE) Automatic installation from .zip: *Sketch/Connect library/Add .ZIP library...* and specify downloaded archive
- Read more detailed instructions for installing libraries[here](https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)
### Update
- I recommend always updating the library: new versions fix errors and bugs, as well as optimize and add new features.
- Through the library manager IDE: find the library as when installing and click "Update"
- Manually: **Delete the folder with the old version** and then put the new one in its place. “Replacement” can not be done: sometimes new versions delete files that will remain when replaced and can lead to errors!

<a id="usage"></a>
## Use of use
### GyverGFX

```cpp
// designer
GyverGFX();
GyverGFX(int x, int y); // sized

// method
void size(int x, int y);    // size
int width();                // width
int height();               // heighten

// ============ PRIMITIVE ============
// fill:
// GFX CLEAR - Clear the figure
// GFX FILL - fill the figure
// GFX STROKE - circle the figure
virtual void dot(int x, int y, uint8_t fill = 1);                   // point
void fill(uint8_t fill = 1);                                        // flood
void clear();                                                       // clear
void lineH(int y, int x0, int x1, uint8_t fill = 1);                // horizontal
void lineV(int x, int y0, int y1, uint8_t fill = 1);                // vertical
void line(int x0, int y0, int x1, int y1, uint8_t fill = 1);        // line
void rect(int x0, int y0, int x1, int y1, uint8_t fill = 1);        // rectangle (corner coordinates)
void rectWH(int x0, int y0, int w, int h, uint8_t fill = 1);        // rectangle (angular coordinates and size)
void roundRect(int x0, int y0, int x1, int y1, uint8_t fill = 1);   // rounded rectangle (corner coordinates)
void roundRectWH(int x0, int y0, int w, int h, uint8_t fill = 1);   // rounded rectangle (angular coordinates and size)
void circle(int x, int y, int radius, uint8_t fill = 1);            // circumference
void bezier(uint8_t *arr, uint8_t size, uint8_t dense, uint8_t fill = 1);     // bezier
void bezier16(int16_t *arr, uint8_t size, uint8_t dense, uint8_t fill = 1);   // Bezier curve 16 bits

// ============ TEXT ============
// Inherit Print. h h
print(любой тип);
println(любой тип);

// output a column byte to the current cursor, taking into account the scale and mode of the text, automatically transfers the cursor
void drawByte(uint8_t bits);
void drawBytes(uint8_t *bytes, int amount);           // massif
void drawBytes_P(const uint8_t *bytes, int amount);   // PROGMEM array

// mode:
// GFX ADD - Add to the buffer
// GFX REPLACE - Replace the information in the buffer
void drawBitmap(int x, int y, const uint8_t *frame, int width, int height, uint8_t invert = 0, byte mode = 0);  // bitmap (mode: GFX ADD/GFX REPLACE)
void textDisplayMode(bool mode);        // insert
bool getTextDisplayMode();              // output

void setCursor(int x, int y);           // point
int getCursorX();                       // cursor
int getCursorY();                       // cursor

void setScale(uint8_t scale);           // scale the text (1-4)
uint8_t getScale();                     // scale

void invertText(bool inv);              // reverse
bool getInvertText();                   // reverse

void autoPrintln(bool mode);            // install automatic text translation
bool getAutoPrintln();                  // Get automatic text translation

void setTextBound(int x0, int x1);      // set the boundaries of the text on x
void resetTextBound();                  // Reset the text output limits to (0, width)
int getTextBoundX0();                   // get the output limit 0
int getTextBoundX1();                   // get the output limit 1

uint16_t strlen_fix(const char *str);   // determine the length of the line with any symbols (including Russian)
uint16_t strlen_fix_P(PGM_P str);       // determine the length of the PGM string with any characters (including Russian)

// ============ DEFINE ============
// defile
// (Before connecting the library)
#define GFX_NO_PRINT                    // disable the text output module (memory savings)
```

#### Embedded icons
The library has a set of 155 8x8 icons, the file *fonts/icons8x8.h*. It is derived as follows:
```cpp
obj.drawBytes_P(GFX_icons::alarm, 8);
obj.drawBytes_P(GFX_icons::email, 8);
```

### RunningGFX
Asynchronous running string. Does not store a string inside itself, so for obvious reasons supports working with:
- Globally established`String`- lines
- Globally established`PROGMEM`- lines
- Globally established`char[]`- lines
- String constants (they are originally global)

Features:
- To automatically update the line in the class should be implemented method`update()`
- The line can be changed during movement:`setText()`does not start the movement again, so when updating the String strings, you can call setText to automatically recalculate the length
- The running line settings (scale, text mode) do not affect the display, more precisely, are automatically set back.
- One object controls one line. If you need several rows running at the same time, create several objects, the example below.

```cpp
// designer
RunningGFX(GyverGFX* gfx);

// method
void setText(const char* str);      // set the text const char*
void setText(String& str);          // string
void setText_P(PGM_P str);          // Install text from PROGMEM (Global)

void invertText(bool inv);          // reverse
void setScale(uint8_t scale);       // scale
void textDisplayMode(bool mode);    // GFX ADD/GFX REPLACE
void setWindow(int16_t x0, int16_t x1, int16_t y);  // install a window (x0, x1, y)
void setSpeed(uint16_t pixPerSec);  // set the speed (pixels per second)

void start();                       // run out
void stop();                        // stop
void resume();                      // continue

// ticker. Return 0 idle, 1 in a new step, 2 at the end of the movement
// You can transfer false so that the display does not update itself.
uint8_t tick(bool update = true);

// Move a line by 1 pixel. You can transfer false so that the display does not update itself.
uint8_t tickManual(bool update = true);
```

<a id="example"></a>
## Example

```cpp
// An example of class inheritance. You need to implement dot and update methods
class MAX7219 : public GyverGFX {
public:
  MAX7219(int width, int height) : GyverGFX(width * 8, height * 8) {}
  void dot(int x, int y, uint8_t fill = GFX_FILL) {
    // ...
  }
  void update() {
    // ...
  }
};
```

```cpp
// Example of RunningGFX
// RunningGFX works with a class that inherits GyverGFX. The GyverMAX7219 Library

MAX7219<4, 1, 5> mtrx;  // one matrix (1x1), pin CS on D5
RunningGFX run1(&mtrx);
RunningGFX run2(&mtrx);
const char pstr_g[] PROGMEM = "Global pgm string";
String str_g = "123";

void setup() {
  mtrx.begin();       // launch
  mtrx.setBright(5);  // brightness 0.15.

  run1.setText("hello");  // string constant
  // run1.setText(str g) // global thong
  run1.setSpeed(15);
  run1.setWindow(0, 16, 0);
  run1.start();

  run2.setText_P(pstr_g); // global
  run2.setSpeed(10);
  run2.setWindow(8, 16, 0);
  run2.start();
}

void loop() {
  run1.tick();
  run2.tick();
}
```

<a id="versions"></a>
## Versions
- v1.0
- v1.1 - Memory optimization
- v1.2 - a small optimization
- v1.3 - added features
- v1.4 - small fixtures
- v1.5 - Disable the GFX NO PRINT text output module
- v1.5.1 - small fixtures
- v1.6 - minor improvements, added running line engine
- v1.7 
  - Improved running line
  - Added settings
  - Added new graphics output tools (drawByte, drawBytes, drawBytes p)
  - Icons added
  - Improved font

<a id="feedback"></a>
## Bugs and feedback
If you find bugs, create **Issue**, or better write to the mail immediately.[alex@alexgyver.ru](mailto:alex@alexgyver.ru)  
The library is open for revision and your **Pull Requests*!

When reporting bugs or incorrect work of the library, it is necessary to specify:
- Library version
- What is used by the IC
- SDK version (for ESP)
- Arduino IDE version
- Are embedded examples that use features and designs that cause bugs in your code working correctly?
- What code was downloaded, what work was expected from it and how it works in reality
- Ideally, attach the minimum code in which the bug is observed. Not a canvas of a thousand lines, but a minimum code.
