/* 
This program will demonstrate the use of the millis() function to execute a 
program with a red LED turning on when a pushbutton is pushed and another blue
LED turning on and then off every 5 seconds. The millis() function will aid in 
ensuring that the blue LED is able to turn on and off seperate to the red LED 
without the need on a delay. 
*/
int PB= 13; //set PB to pin 13 
int red= 12; //set red to pin 12 

const int blue = 8;  // the number of the LED pin
int ledState = LOW;  // ledState used to set the LED
unsigned long previousMillis = 0;  // will store last time LED was updated
const long interval = 5000;  // interval set to 5000 milliseconds 

void setup() {

pinMode(PB, INPUT_PULLUP); //set PB value to as a pullup input 
pinMode(red, OUTPUT); //set red as an output 
pinMode(blue, OUTPUT); //set blue as an output
Serial.begin(9600); //begin the serial print at 9600 bps 
}

void loop() {

int state= digitalRead(PB);//read the state of the pushbutton 
digitalWrite(red, state);// turn the red LED ON when puudhbutton state is ON

 unsigned long currentMillis = millis(); 

  if (currentMillis - previousMillis >= interval) { //if millis is greater >= 5000 ms
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) { 
      ledState = HIGH; 
    } else {
      ledState = LOW; // else LED state is off 
    }


    digitalWrite(blue, ledState);//blue LED is ON when ledSate is TRUE 
  }
}