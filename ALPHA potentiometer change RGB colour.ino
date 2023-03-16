/*
This program will demonstrate how the colour change of an RGB LED from black (off since black cannot
be replicated using LED's) to white. The LED will go through different colour variations between black 
and white. The colour variations will be controlled using a potentiometer. 
*/

int Pot= A0; //set Pot as A0
int Red= 9; //set Red as 9
int Blue= 10; //set Blue as 10
int Green= 11; //set Green as 11
 
void setup() {

pinMode(Pot, INPUT); //set Pot as an INPUT 
pinMode(Red, OUTPUT); //set Red as an OUTPUT 
pinMode(Blue, OUTPUT);  //set Blue as an OUTPUT 
pinMode(Green, OUTPUT);  //set Green as an OUTPUT 
Serial.begin(9600);  //serial print begins at 9600 bps 
}

void loop() {

int value= analogRead(Pot); //set value as analog read the potentiometer value 
float Ain= (value*255.0)/1023.0; //formula to go from bit value to colour scheme (0-255 instead of 0-1023)

if (Ain >= 0 && Ain < 21.25) { //if read value is between 0 and 21.25
analogWrite(Red, 0); //set designated values for black 
analogWrite(Green, 0); //set designated values for black 
analogWrite(Blue, 0); //set designated values for black 
}
else if (Ain >= 21.25 && Ain <= 42.5) { //else if value is between and 
analogWrite(Red, 137); //set designated values for colour variation
analogWrite(Green, 0); //set designated values for colour variation
analogWrite(Blue, 0); //set designated values for colour variation
}    

else if (Ain >= 42.5 && Ain <= 63.75 ) { //else if value is between and 
analogWrite(Red, 255); //set designated values for colour variation
analogWrite(Green, 0); //set designated values for colour variation
analogWrite(Blue, 0);  //set designated values for colour variation
}      
else if (Ain >= 63.75 && Ain <= 85 ) { //else if value is between and 
analogWrite(Red, 255); //set designated values for colour variation
analogWrite(Green, 0); //set designated values for colour variation
analogWrite(Blue, 230); //set designated values for colour variation
}  
else if (Ain >= 85 && Ain <= 106.25) { //else if value is between and 
analogWrite(Red, 102); //set designated values for colour variation
analogWrite(Green, 0); //set designated values for colour variation
analogWrite(Blue, 230); //set designated values for colour variation
}    
else if (Ain >= 106.25 && Ain <= 127.5) { //else if value is between and  
analogWrite(Red, 0); //set designated values for colour variation
analogWrite(Green, 102); //set designated values for colour variation
analogWrite(Blue, 255); //set designated values for colour variation
}  
else if (Ain >= 127.5 && Ain <= 148.75) { //else if value is between and 
analogWrite(Red, 0); //set designated values for colour variation
analogWrite(Green, 222); //set designated values for colour variation
analogWrite(Blue, 255); //set designated values for colour variation
}    
else if (Ain >= 148.75 && Ain <= 170 ) { //else if value is between and 
analogWrite(Red, 0); //set designated values for colour variation
analogWrite(Green, 255); //set designated values for colour variation
analogWrite(Blue, 137); //set designated values for colour variation
}    
else if (Ain >= 170 && Ain <= 191.25 ) { //else if value is between and 
analogWrite(Red, 51);  //set designated values for colour variation
analogWrite(Green, 255); //set designated values for colour variation
analogWrite(Blue, 0);  //set designated values for colour variation
} 
else if (Ain >= 191.25 && Ain <= 212.5) {  //else if value is between and 
analogWrite(Red, 255); //set designated values for colour variation
analogWrite(Green, 230); //set designated values for colour variation
analogWrite(Blue, 0); //set designated values for colour variation
}    
else if (Ain >= 212.5 && Ain <= 233.75) { //else if value is between and 
analogWrite(Red, 255); //set designated values for colour variation
analogWrite(Green, 243); //set designated values for colour variation
analogWrite(Blue, 125); //set designated values for colour variation
}    
else{ //else set the following:
analogWrite(Red, 255); //set designated values for colour variation
analogWrite(Green, 255); //set designated values for colour variation
analogWrite(Blue, 255); //set designated values for colour variation
}    

Serial.print("Ain= "); //serial print Ain=
Serial.print("\t"); //serial print a space 
Serial.println(Ain); //serial print Ain
delay(50); //leave a 50 milliseconds delay 

}