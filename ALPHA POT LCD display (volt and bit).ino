/*
This program will demonstrate the how to have an lcd display bit value and voltage value using
a potentiometer. It will do so by directly dispalying the bit value on the first line, then
calculate the voltage value and display it on the second line. 
*/
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int A = A0; //set Ain to A0 

void setup() {

pinMode (A, INPUT); //set A as an inout 
Serial.begin(9600); //serial print begin at 9600 bps
lcd.begin(16, 2); //lcd display will take 16 coloums and 2 rows 
}

void loop() {

int Ain = analogRead(A); //set Ain as analog reading input A

lcd.setCursor(0,0); //set the lcd cursor to begin at coluom 0, row 0 
lcd.print("Bit value="); //lcd print "bit value="
lcd.print(Ain); //lcd print the bit value of Ain 

float voltage = 5.0*Ain/1023.0; // formula to turn analog value (bit value) into voltage value
lcd.setCursor(0,1); //set lcd cursor to begin at colum 0 row 1 
lcd.print("Voltage="); //lcd print "Voltage=""
lcd.print(voltage); //lcd print the calculated voltage 

delay(10); //create a 10 millisecond delay and clear the lcd 
lcd.clear();

}

