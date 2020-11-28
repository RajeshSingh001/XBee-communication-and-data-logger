 
  
//#include <Wire.h> //BH1750 IIC Mode 
//#include <math.h> 
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup()
{
 // Wire.begin();
  lcd.begin(20,4);
  Serial.begin (9600);
}
  
  
  
void loop()
{ 
   int sensorValue = analogRead(A0);
   int FSR1=sensorValue/2;
   lcd.print(FSR1);
   Serial.println(FSR1);
   delay(2000);
    lcd.clear();
}
  
  
  
  
