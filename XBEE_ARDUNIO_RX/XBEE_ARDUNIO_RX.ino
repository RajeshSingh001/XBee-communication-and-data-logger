#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  lcd.begin(20, 4);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() 
{
  // print the string when a newline arrives:
    
  if (stringComplete) 
  {   
     lcd.setCursor(0, 0);
     lcd.print(inputString[16]);
     lcd.print(inputString[17]);
     Serial.print("FSR1:"); 
     Serial.print(inputString[16]); 
     Serial.print(inputString[17]);
     Serial.println(inputString[18]); // enter for next line
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available())
  {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar =='\n') 
    {
      stringComplete = true;
    } 
  }
}


