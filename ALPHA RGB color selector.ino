/* 
This program will demonstrate a selection of three colours, red, green, blue depending on an input (potentiometer reading).
It will use if, if else, else functions in order to acheive this. 
*/

// analog input =  1023 ,analog output = 255 
int Ain = A0; //set A0 to Ain
int red = 11; //set pin 11 to red
int blue = 10; //set pin 10 to blue
int green = 9; //set pin 9 to green

void setup() {
 
pinMode (Ain, INPUT ); // Specify Ain as input
pinMode(red, OUTPUT);  // Specify red as output
pinMode(blue, OUTPUT); // Specify blue as output
pinMode(green, OUTPUT); // Specify green as output
Serial.begin(9600); //begin serial print at 9600 bps 

}

void loop() {

int Ain = analogRead(A0); // set Ain to "reading analog input A0"

float voltage = 5.0*Ain/1023.0; // formula to turn analog value into voltage value
Serial.print("Voltage="); //start serial print "Voltage=""
Serial.print("\t"); // leave a space 
Serial.print(voltage); //safter space, write the answer to the previous equation 


if (Ain >= 0 && Ain < 341) { // if Ain has a value greater than or equal to 0 and less than 341
analogWrite(red, 91); //turn on red LED at value 91 
Serial.print("    Red="); //then serial print "  Red="
Serial.print("\t"); // leave a space 
Serial.println("ON"); // show the status of the LED as ON then move to the next monitor line 
}

else if (Ain >= 341 && Ain <= 682) { // or else if Ain has a value greater than or equal to 341 and less than 682
analogWrite(blue, 91); //turn on blue LED at value 91 
Serial.print("     Blue="); //then serial print "  Blue="
Serial.print("\t"); //leave a space
Serial.println("ON"); // show the status of the LED as ON then move to the next monitor line
}

else { // or else Ain has a value greater than 682 
analogWrite(green, 91); //turn on green LED at value 91
Serial.print("     Green="); //then serial print "  Green="
Serial.print("\t"); //leave a space
Serial.println("ON"); // show the status of the LED as ON then move to the next monitor line
}

}
