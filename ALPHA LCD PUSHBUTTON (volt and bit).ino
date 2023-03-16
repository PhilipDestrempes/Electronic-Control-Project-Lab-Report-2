/*
This program will demonstrate the how to have an lcd display bit value and voltage value using
a pushbutton. It will do so by directly dispalying the bit value on the first line, then
calculate the voltage value and display it on the second line. 

An analog input will be used to display the bit value and a digital input will be used to display
the voltage. This will be acheived using an if else function 
*/

#include <LiquidCrystal.h> 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int A = A0; //set A as A0
int Button = 8; //set button to 8

void setup() {

pinMode (A, INPUT); //set A as an input 
pinMode(Button, INPUT_PULLUP); //set button as a pullup input 
lcd.begin(16, 2); ///lcd display will take 16 coloums and 2 rows 
}

void loop() {

float voltage = 5.0*Ain/1023.0; // formula to turn analog value into voltage value 
int Ain = analogRead(A); //set Ain as analog read A input 


if (digitalRead(Button)==LOW) { //if button value is LOW
lcd.setCursor(0,0); //set the lcd cursor to begin at coluom 0, row 0 
lcd.print("Bit value="); //set lcd print to display "Bit value="
lcd.print(Ain); //set the lcd print to display Ain 
}

else { //else is button value is not LOW
lcd.setCursor(0,0); //set the lcd cursor to begin at coluom 0, row 0 
lcd.print("Voltage="); //lcd print "Voltage=""
lcd.print(voltage); //lcd print the voltage value 
}

delay(10); //create a 10 millisecond delay and clear the lcd 
lcd.clear(); 

}