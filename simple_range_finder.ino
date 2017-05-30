/*
 * Author: Domenico Leopardi
 * Date:2017/05/29
 * IDE V1.8.2
 * Email: domenico.leopardi@gmail.com
 * Function: Simple Range Finder
 */
// initialize the library with the numbers of the interface pins
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

unsigned long pulseWidth;

void setup()                                                                                     
{
  //Serial.begin(115200); // Start serial communications
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16,2);

  pinMode(9, OUTPUT); // Set pin 2 as trigger pin
  digitalWrite(9, LOW); // Set trigger LOW for continuous read

  pinMode(8, INPUT); // Set pin 3 as monitor pin


  lcd.setCursor(0,0);  //Display position
  lcd.print("Range:");
}
void loop()
{

  pulseWidth = pulseIn(8, HIGH); // Count how long the pulse is high in microseconds

  // If we get a reading that isn't zero, let's print it
  //if(pulseWidth != 0)
  //{
    pulseWidth = pulseWidth / 10; // 10usec = 1 cm of distance
    //Serial.println(pulseWidth); // Print the distance
    
    lcd.setCursor(0,1);  //Display position
    if(pulseWidth >= 100)
      lcd.print( String(pulseWidth/100.0) + " m      ");
    else
      lcd.print( String(pulseWidth) + " cm     ");
      
    delay(100);
  //}
  
 }

