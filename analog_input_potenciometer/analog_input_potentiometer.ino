/*
  Analog Input test with a Potenciometer

  Describe what it does in layman's terms.  Refer to the components
  attached to the various pins:
  
  Potenciometer asigned to pin A0

  The circuit:
  Potenciometer

  Created 2/27/19
  By Miguel Osuna
  Modified: 
  By:
*/
int potPin = A0;

void setup()
{
  //Set the potenciometer pin and asign it as input
  pinMode(potPin, INPUT);
  Serial.begin(9600);
  
}

void loop()
{
  //Look for anything in serial port
  if(Serial.read())
    Serial.println(analogRead(potPin)); //Print the value returned from analogRead function
}

