/* 
This program will display the bit and voltage value of a potentiometer using the 
serial monitor command. The potentiometer will also control the shading of an LED. 
*/

int LED= 9; //set pin 9 as LED
int blue= 6; //set pin 6 as blue 
int green= 5; //set pin 5 as green 

void setup() {

pinMode(A0, INPUT); //set pin A0 as an input
pinMode(9, OUTPUT); //set pin 9 as an output
pinMode(6, OUTPUT); //set pin 6 as an output
pinMode(5, OUTPUT); //set pin 5 as an output
Serial.begin(9600); //begin serial print at 9600 bps
}

void loop() {

int pot= analogRead(A0); //read bit values from A0 
float voltage= 5.0*pot/1023.0; //go from bit value to voltage

Serial.print("PotInput ="); //serial print potentiometer input=
Serial.print("\t"); //leave a space
Serial.print(pot); //serial print the potentiometer bit value
Serial.print("\t"); //leave a space
Serial.print("Voltage ="); //serial print potentiometer input= 
Serial.print("\t"); //leave a space 
Serial.println(voltage); //serial print the computed voltage from the bit value 

analogWrite(LED, pot); //LED shading affected by potentiometer 
analogWrite(blue, 91); //set blue LED ON at 91 density 
analogWrite(green, 91); //set greeen LED ON at 91 density 

}
