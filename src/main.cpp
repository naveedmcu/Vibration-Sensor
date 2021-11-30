#include <Arduino.h>
#include <elapsedMillis.h>

elapsedMillis SendTime_Sec;
unsigned long SendTime_Sec_Interval = 1000;

#define VBpin 4
/**/
void setup()
{
  // put your setup code here, to run once:
  pinMode(VBpin, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  Serial.begin(115200);
}
/**/
long data;
void loop()
{
  // put your main code here, to run repeatedly:
  delay(3000);
  Serial.println("Serial Port");
  Serial.println("Serial Port");
  Serial.println("Serial Port");
  Serial.println("Serial Port");
  while (1)
  {
    /* code */
    data = pulseIn(VBpin, HIGH);
    if (SendTime_Sec >= SendTime_Sec_Interval)
    {
      SendTime_Sec = 0;
      if (data >= 25000)
      {
        digitalWrite(2, HIGH);
        Serial.print("Vibration per Second:");
        Serial.println(data);
      }
      else
      {
        digitalWrite(2, LOW);
        Serial.println("Vibration per Second:0");
      }
    }
  }
}
/**/