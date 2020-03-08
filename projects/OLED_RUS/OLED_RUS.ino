#include <U8glib.h>
#include "ruscu12.h"

U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_NONE);  // I2C / TWI 

void setup(void) {
  // flip screen, if required
  // u8g.setRot180();
  u8g.setFont(ruscu12);
}

void loop()
{
u8g.firstPage(); 

    do
    {
      u8g.setColorIndex(1);    // цвет белый
      u8g.setPrintPos(10, 15); 
      u8g.print("Русский");
      u8g.setPrintPos(50, 30); 
      u8g.print("Текст");
      u8g.println(); 
    } while( u8g.nextPage() );
}
