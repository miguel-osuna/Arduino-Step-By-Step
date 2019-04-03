/*
  Sketch title

  Describe what it does in layman's terms.  Refer to the components
  attached to the various pins.

  The circuit:
  * list the components attached to each input
  * list the components attached to each output

  Created day month year
  By author's name
  Modified day month year
  By author's name

  http://url/of/online/tutorial.cc

*/


int ledPin = 8; //Pin used for the LEDz

void setup()
{
  //We configure the pin as an OUTPUT
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  
}

void loop() 
{
  int i;
  //This is not necessary for this case, because its on a loop
  for(i = 0; i < 255; i++)
  {
    digitalWrite(ledPin,HIGH); // Sets the digital pin 8 on
    delay(100); // Waits for 100 ms
    digitalWrite(ledPin, LOW); // Sets the digital pin 8 off
    delay(100); //Waits for 100 ms
  }
}
