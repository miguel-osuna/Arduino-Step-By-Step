/*
  Analog and Digital Pins Test

  Describe what it does in layman's terms.  Refer to the components
  attached to the various pins:
  The programs Turns On an LED with the PWM analog output by changing the potentiometer position and by pressing the push-button.
  
  Potentiometer asigned to Analog Pin A0
  LED asigned to digital Pin 9
  Push-button asigned to Pin 8

  The circuit: 
  1 Potentiometer
  1 LED
  1 Push-button
  1 Resistor

  Created 2/27/19
  By Miguel Osuna
  Modified: -/-/-
  By: -----------
*/

int ledPin = 9; //For the analog output
int buttonPin = 8; //For the digital input
int potPin = A0; //For the analog input

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop()
{ 
  int potValue = analogRead(potPin); //Get the potenciometer analog value. Base 1023.
  int buttonState = digitalRead(buttonPin); //Read the state of the button. HIGH or LOW.
  int mapedValue = map(potValue, 0, 1023, 0, 255); //map(value, fromLow, fromHigh, toLow, toHigh)
  
  if(buttonState)
  {
    Serial.println(mapedValue); //Shows the maped value in serial monitor
    analogWrite(ledPin, mapedValue); //PWM value from the Potenciometer input. Base 255.
  }

  else
    digitalWrite(ledPin, LOW); //We put LOW in the pin because it overwrites the value variable
}

