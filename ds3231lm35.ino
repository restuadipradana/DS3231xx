/*
* Arduino DS3231 Real Time Clock Module Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
* DS3231 Library made by Henning Karlsen which can be found and downloaded from his website, www.rinkydinkelectronics.com.
*
*/
#include <DS3231.h>
#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
DS3231  rtc(SDA, SCL);
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 
byte degree[8] = {                                              // this is a code to write a single lcd character block
  0b00000,
  0b11100,
  0b10100,
  0b11100,
  0b00000,
  0b00000,
  0b00000,
};
float suhu = 0;
int nilai = 0;
int sensor = A0;
Time t; //update saklar

void setup() { 
  pinMode(13, OUTPUT); //update saklar
  Serial.begin(115200); //update saklar
   rtc.begin(); // Initialize the rtc object
   
   // The following lines can be uncommented to set the date and time
   //rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
   //rtc.setTime(12, 0, 0);     // Set the time to 12:00:00 (24hr format)
   //rtc.setDate(1, 1, 2014);   // Set the date to January 1st, 2014
   lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
   lcd.createChar(5, degree);
}
void loop() {
  t = rtc.getTime(); //update saklar
  //Serial.println(t.hour); //update saklar
   nilai = analogRead(sensor);
   suhu = (5.0 * nilai * 100.0)/1024.0;
   lcd.setCursor(0,0);
   lcd.print(rtc.getTimeStr());
   lcd.setCursor(9, 0);
   lcd.print(suhu);
   lcd.write(5);
   lcd.print("C  ");
 
   lcd.setCursor(0,1);
   lcd.print(rtc.getDateStr());

   //relay (jam 6 sore - jam 6 pagi lampu menyala)
  if ((t.hour >= 18 ) || (t.hour <=5)) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
 
   delay(1000); 
   
}
