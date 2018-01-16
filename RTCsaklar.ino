#include <DS3231.h>
DS3231  rtc(SDA, SCL);
Time t; //update saklar

void setup() { 
  pinMode(10, OUTPUT); //update saklar
  Serial.begin(115200); //update saklar
   rtc.begin(); // Initialize the rtc object
   
   // The following lines can be uncommented to set the date and time
   //rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
   //rtc.setTime(12, 0, 0);     // Set the time to 12:00:00 (24hr format)
   //rtc.setDate(1, 1, 2014);   // Set the date to January 1st, 2014
   
}
void loop() {
  t = rtc.getTime();
   
   //Serial.println(rtc.getTimeStr());
   //Serial.println(rtc.getDateStr());

   //relay (jam 6 sore - jam 6 pagi lampu menyala)
  if ((t.hour >= 18 ) || (t.hour <=5)) {
    digitalWrite(10, LOW);
  } else {
    digitalWrite(10, HIGH);
  }
 
   delay(1000); 
   
}
