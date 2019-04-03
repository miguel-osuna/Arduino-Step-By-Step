/*
  Digital Sound Sensor
    
  Describe what it does in layman's terms.  Refer to the components
  attached to the various pins:
  The code detects a sampling sound to know if its loud or quite enough
  
  Digital Sound Sensor Asigned to Pin 6
  LED Asinged to Pin 7

  The circuit: 
  1 Digital Sound Sensor
  1 LED 
  1 Resistor

  Created 7/3/19
  By Miguel Osuna
  Modified: -/-/-
  By: -----------
*/

const int ledPin = 7;
const int digitalSoundSensor = 6;
unsigned long timer;
int waitingTime = 0; //Time in milliseconds
bool alarm = false;

void setup()
{
  //Configure the components
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(digitalSoundSensor, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorStatus = digitalRead(digitalSoundSensor);

  if(sensorStatus == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    timer = millis();

    if(!alarm)
    {
      Serial.println("LOUD!");
      alarm = true;
    }

    if( (millis() - timer) >= waitingTime && alarm)
    {
      digitalWrite(ledPin, LOW);
      alarm = false;
      Serial.println("QUIET!");
    }
  }
}

