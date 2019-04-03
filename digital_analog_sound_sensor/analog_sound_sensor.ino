/*
  Analog Sound Sensor
    
  Describe what it does in layman's terms.  Refer to the components
  attached to the various pins:
  The code detects a sampling sound to know if its loud or quite enough
  
  Analog Sound Sensor Asigned to Pin A0
  LED Asinged to Pin 7

  The circuit: 
  1 Analog Sound Sensor
  1 LED 
  1 Resistor

  Created 7/3/19
  By Miguel Osuna
  Modified: -/-/-
  By: -----------
*/

const int ledPin = 7;
const int soundSensorPin = A0;
int minValue;
int maxValue;
int timeSampling = 200; //In milliseconds to sample data
int volume;
unsigned long timer;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(soundSensorPin, INPUT);
  Serial.begin(9600);
  resetValues();
}

void loop()
{
  int volume;
  int senseValue = analogRead(soundSensorPin);

  if(senseValue < minValue)
    minValue = senseValue;

  else if(senseValue > maxValue)
    maxValue = senseValue;

  if((millis() - timer) >= timeSampling)
  {
    volume = maxValue - minValue;
    //Serial.println(volume);
    resetValues();
  }

  //The value of a clap seems to be higher than 15, so this is the comparisson
  if(volume > 15)
  {
    Serial.println("LOUD");
    digitalWrite(ledPin, HIGH);
  }

  else
  {
    Serial.println("QUIET");
    digitalWrite(ledPin, LOW);
  }
}

void resetValues()
{
  //We set to the opposite value, in order to substitute the one from the reading
  minValue = 1024;
  maxValue = 0;
  timer = millis();
}

