/*
  LDR Test

  Describe what it does in layman's terms.  Refer to the components
  attached to the various pins:
  The program reads an analog voltage input that comes from the voltage dropped in an LDR
  
  LDR asigned to Pin A0 as Input

  The circuit: 
  1 LDR
  1 Resistor

  Created 2/28/19
  By Miguel Osuna
  Modified: -/-/-
  By: -----------
*/
const int ldrPin = A0;

void setup()
{
	pinMode(ldrPin, INPUT);
	Serial.begin(9600);
}

void loop()
{
	Serial.println(analogRead(ldrPin));
}