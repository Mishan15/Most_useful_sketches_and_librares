// Подключаем стандартную библиотеку LiquidCrystal
#include <LiquidCrystal.h>

// Инициализируем объект-экран, передаём использованные
// для подключения контакты на Arduino в порядке:
// RS, E, DB4, DB5, DB6, DB7

/*byte P[8] =
{
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
};
byte r[8] =
{
  B00000,
  B11110,
  B10001,
  B10001,
  B11110,
  B10000,
  B10000,
  B10000,
};
byte i[8] =
{
  B00000,
  B10001,
  B10011,
  B10101,
  B11001,
  B11001,
  B10001,
  B10001,
};
byte v[8] =
{
  B00000,
  B11110,
  B10001,
  B10001,
  B11110,
  B10001,
  B10001,
  B11110,
};
byte e[8] =
{
  B00000,
  B11111,
  B10000,
  B10000,
  B11111,
  B10000,
  B10000,
  B11111,
};
byte t[8] =
{
  B00000,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
};
byte m[8] =
{
  B00000,
  B10001,
  B11011,
  B10101,
  B10101,
  B10001,
  B10001,
  B10001,
};//*/


byte sten1[8] =
{
  B11111,
  B01001,
  B00101,
  B00111,
  B00111,
  B00101,
  B01001,
  B11111,
};
byte sten2[8] =
{
  B11111,
  B10010,
  B10100,
  B11100,
  B11100,
  B10100,
  B10010,
  B11111,
};
byte bol[8] =
{
  B00000,
  B01110,
  B10101,
  B11011,
  B10101,
  B01110,
  B00000,
  B00000,
};
byte target[8] =
{
  B00000,
  B00100,
  B00100,
  B11011,
  B00100,
  B00100,
  B00000,
  B00000,
};
byte lastplase[2];
LiquidCrystal lcd(4, 5, 10, 11, 12, 13);

void setup()
{
  Serial.begin(9600);
  lcd.createChar(1, sten1);
  lcd.createChar(2, sten2);
  lcd.createChar(3, bol);
  lcd.createChar(4, target);

  /*   // устанавливаем размер (количество столбцов и строк) экрана

     // печатаем первую строку
     lcd.print("Hello world!");
     // устанавливаем курсор в колонку 0, строку 1. То есть на
     // самом деле это вторая строка, т.к. нумерация начинается с нуля
     lcd.setCursor(0, 1);
     // печатаем вторую строку
     lcd.print("from Ardyino");
     delay(5000);//*/
  lcd.begin(16, 2);

  /*lcd.createChar(3, i);
  lcd.createChar(4, v);
  /*lcd.createChar(5, e);
  lcd.createChar(6, t);
  lcd.createChar(7, m);


  */lcd.setCursor(0, 0);               // Устанавливаем курсор в начало 1 строки
  lcd.print("Bol");
  lcd.setCursor(0, 1);              // Устанавливаем курсор в начало 1 строки
  lcd.print("Game!");
  lcd.setCursor(5, 0);               // Устанавливаем курсор в начало 1 строки
  lcd.print("\1");
  lcd.setCursor(15, 0);               // Устанавливаем курсор в начало 1 строки
  lcd.print("\2");
  lcd.setCursor(5, 1);               // Устанавливаем курсор в начало 1 строки
  lcd.print("\1");
  lcd.setCursor(15, 1);               // Устанавливаем курсор в начало 1 строки
  lcd.print("\2");/*
  lcd.setCursor(2, 0);               // Устанавливаем курсор в начало 1 строки
  lcd.print("\3");
  lcd.setCursor(3, 0);               // Устанавливаем курсор в начало 1 строки
  lcd.print("\4");
  lcd.setCursor(4, 0);               // Устанавливаем курсор в начало 1 строки
  lcd.print("\5");
  lcd.setCursor(5, 0);               // Устанавливаем курсор в начало 1 строки
  lcd.print("\6");
  //lcd.print(" ");
  lcd.setCursor(7, 0);               // Устанавливаем курсор в начало 1 строки
  lcd.print("\7");
  lcd.setCursor(8, 0);               // Устанавливаем курсор в начало 1 строки
  lcd.print("\3");
  lcd.setCursor(9, 0);               // Устанавливаем курсор в начало 1 строки
  lcd.print("\2");
  lcd.print("! ");
  delay(2000);
  lcd.print("@^@");
  lcd.setCursor(12, 1);
  lcd.print("__/");//*/
  //@^@
  //\_/
}
byte e = 0;

void loop() {

  byte x = 0;
  byte y = 0;
 
  analogWrite(3, analogRead(0) / 4);
  byte q = analogRead(1) / 125;
  byte w = analogRead(2) / 500;
  /*  Serial.print(q);
    Serial.print("  ");
    Serial.println(w);//*/
  if (w == 0) {
    e = 1;
  } else if (w == 2) {
    e = 0;
  };


  /*x = random(0, 9);
  y = random(0, 2);
  lcd.setCursor(x + 6, y);
  lcd.print("\4 ");
  delay(100);
  Serial.print(x);
  Serial.print(";");
  Serial.println(y);//*/



  if (lastplase[0] != q) {
    lcd.setCursor(lastplase[0] + 6, lastplase[1]);            // Устанавливаем курсор в начало 1 строки
    lcd.print(" ");
    lastplase[0] = q;
  } else if (lastplase[1] != e) {
    lcd.setCursor(lastplase[0] + 6, lastplase[1]);            // Устанавливаем курсор в начало 1 строки
    lcd.print(" ");
    lastplase[1] = e;
  };

  lcd.setCursor(q + 6, e);            // Устанавливаем курсор в начало 1 строки
  lcd.print("\3");
  lcd.setCursor(15, 0);               // Устанавливаем курсор в начало 1 строки
  lcd.print("\2");
  lcd.setCursor(15, 1);               // Устанавливаем курсор в начало 1 строки
  lcd.print("\2");
  delay(1);



















  /*  if (w == 0) {
      e = 1;
      for (byte i = 6; i < 15; i++) {
        if (i == q) {
          lcd.setCursor(q + 6, e);            // Устанавливаем курсор в начало 1 строки
          lcd.print("\3");
                     // Устанавливаем курсор в начало 1 строки

        } else {
          lcd.setCursor(i, 0);               // Устанавливаем курсор в начало 1 строки
          lcd.print(" ");
          lcd.setCursor(i, 1);               // Устанавливаем курсор в начало 1 строки
          lcd.print(" ");
        };
      };
      lcd.setCursor(q + 6, e);            // Устанавливаем курсор в начало 1 строки
      lcd.print("\3");
    } else if (w == 2) {
      e = 0;
      for (byte i = 6; i < 15; i++) {
        if (i == q) {

        } else { //*
          lcd.setCursor(i, 0);               // Устанавливаем курсор в начало 1 строки
          lcd.print(" ");
          lcd.setCursor(i, 1);               // Устанавливаем курсор в начало 1 строки
          lcd.print(" ");
        };//*
      };
      lcd.setCursor(q + 6, 0);            // Устанавливаем курсор в начало 1 строки
      lcd.print("\3");
    } else {
      for (byte i = 6; i < 15; i++) {
        lcd.setCursor(i, 0);               // Устанавливаем курсор в начало 1 строки
        lcd.print(" ");
        lcd.setCursor(i, 1);               // Устанавливаем курсор в начало 1 строки
        lcd.print(" ");
      };
    };*/
}


