/*
This program will use an LCD and will use input voltage to dertermine 
the unknown resistance of a resistor (in essence will act as an ohm-meter).
This will be acheived using known values and ohms law to determin this resistance.
The resistance of the unknown resistor will then be displayed on the LCD. 
*/

byte customChar[8] = { // custom byte combination to create ohm symbol on LCD
    0b00000,
    0b01110,
    0b10001,
    0b10001, 
    0b01010, 
    0b11011,
    0b00000,
    0b00000
};

#include <LiquidCrystal.h> 

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int Ain = A0; //set pin A0 to Ain
int Ra = 996; //set value 996 to Ra
int Vin = 5.0; //set value 5.0 to Vin

void setup() {

Serial.begin(9600); //begin serial display at 9600 bps
lcd.createChar(0, customChar); //set the custom byte combination for ohms
lcd.begin(16, 2); //begin lcd display for 16 colums and 2 rows
}

void loop() {

int Abit= analogRead(Ain); //Read the analog value (Ain) and set it to Abit

float Av= 5.0*Abit/1023.0; //equation to turn bit value into voltage value

float Ia = (Vin-Av)/(Ra); //equation to determine current
float Res = (Av)/(Ia); //equation to determine unknown resistance (Res)

Serial.print("Res=" ); //serial print resistance=
Serial.print("\t"); //leave a space 
Serial.println(Res); //serial print the found resistance value (Res)

lcd.setCursor(0,0); //set the lcd begin cursor to colum 0, row 0
lcd.print("Res="); //lcd print resistance=
lcd.print(Res); //lcd print the found resistance value 
lcd.write((byte)0); //lcd write the created byte 

delay(500); //clear the lcd every 500 milliseconds
lcd.clear(); 

}

