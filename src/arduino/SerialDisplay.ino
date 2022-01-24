/*
  LiquidCrystal Library - Serial Input

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch displays text sent over the serial port
 (e.g. from the Serial Monitor) on an attached LCD.

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalSerialDisplay

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int velocidad = 300;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // initialize the serial communications:
  Serial.begin(115200);
}

void loop() {
  // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      /*String alex = Serial.readString();
      lcd.print(alex);*/
      mostrarTexto(Serial.readString();
    }
  }
}

void mostrarTexto(String texto_fila){
  
  //Obtenemos el tamaño del texto

  int tam_texto = texto_fila.length();


   //Obtenemos entrada del texto por la izquierda de la segunda fila
  for(int i = 16; i>=1; i--){
   //limpiamos la pantalla
   lcd.clear();

   //Situamos el cursos
   lcd.setCursor(i, 1);

   //Escribimos el texto
   lcd.print(texto_fila);

   //esperamos
   delay(velocidad);
  }

  //Desplazamos el texto hacia la derecha
  for(int i=1; i<=tam_texto;i++){
    String texto = texto_fila.substring(i-1);
    //limpiamos la pantalla
    lcd.clear();

    //situamos el cursor
    lcd.setCursor(0, 1);

    //Escribimos el texto
    lcd.print(texto);

    //esperamos
    delay(velocidad);
  }

  //Obtenemos entrada del texto por la izquierda
  for(int i = tam_texto; i>0; i--){
   String texto = texto_fila.substring(i-1);

   //limpiamos la pantalla
   lcd.clear();

   //Situamos el cursos
   lcd.setCursor(0,0);

   //Escribimos el texto
   lcd.print(texto);

   //esperamos
   delay(velocidad);
  }

  //Desplazamos el texto hacia la derecha
  for(int i=1; i<=16;i++){

    //limpiamos la pantalla
    lcd.clear();

    //situamos el cursor
    lcd.setCursor(i, 0);

    //Escribimos el texto
    lcd.print(texto_fila);

    //esperamos
    delay(velocidad);
  }

}
