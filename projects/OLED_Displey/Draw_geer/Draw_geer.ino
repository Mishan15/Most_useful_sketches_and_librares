#include "U8glib.h"

/*
   fynctions;
   u8g.drawLine(0, 63, 128, 63);
   u8g.drawLine(0, 62, 128, 62);
   u8g.drawDisc(32, 53, 9);
*/

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);

#define lowerXdistanse 31 // 0-63
#define leftYdistanse 63 // 0-127
#define maxDispleyHigh 63
#define maxDspleyLength 127

uint8_t draw_state = 0;
int i = 0, q = 0;
bool step = 0;

void drawSystem(void) {
  u8g.drawLine(0, maxDispleyHigh - lowerXdistanse, maxDspleyLength, maxDispleyHigh - lowerXdistanse);
  u8g.drawLine(leftYdistanse, 0, leftYdistanse, maxDispleyHigh);
}

void drawGraphick() {
  float xlast = 0, ylast = 0, x = 0, y = 0;
  int dip = 100;
  step = 0;
  for (x = -1 * dip; x <= dip; x++) {
    y = 0.1*(x*x-7+4*x);
    if (y <= maxDispleyHigh - lowerXdistanse && y >= - 1 * lowerXdistanse && x <= maxDspleyLength - leftYdistanse && x >= -1 * leftYdistanse) {
      if (step == 0) xlast = x, ylast = y, step = 1;
      u8g.drawLine(leftYdistanse + xlast, maxDispleyHigh - lowerXdistanse - ylast, leftYdistanse + x, maxDispleyHigh - lowerXdistanse - y);
      xlast = x; ylast = y;
    }
    delay(1);
  }
}

void draw() {
  drawSystem();
  drawGraphick();
}

void setup(void) {
  Serial.begin(9600);
  u8g.firstPage();
  do {
    u8g.drawPixel(0, 0);
  } while ( u8g.nextPage() );
}

void loop(void) {

  u8g.firstPage();
  do {
    draw();
  } while ( u8g.nextPage() );
}
