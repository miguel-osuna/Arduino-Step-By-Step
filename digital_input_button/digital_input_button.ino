/*
  Testing button as digital Input

  Describe what it does in layman's terms.  Refer to the components
  attached to the various pins:
  
  Button asigned to pin 9
  LED asigned to pin 8

  The circuit:
  * 1 Button
  * 1 LED
  * 1 Resistor

  Created 2/27/19
  By Miguel Osuna
  Modified: 
  By:
*/


int buttonPin = 8; //Pin used for the Button
int ledPin = 9; //Pin used for the LED
int cnt = 0; //Counter for amount of times a button is pressed

void setup()
{
  //We initialize the serial port
  Serial.begin(9600);
  
  //We configure the pin as an OUTPUT
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  // digitalWrite(buttonPin, LOW);
  digitalWrite(ledPin, LOW);
  
}

void loop() 
{
  int i;
  int buttonState = 0;

  //We read the button state to seek if its HIGH or LOW
  buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH && cnt < 5)
  {
    digitalWrite(ledPin,HIGH); // Sets the digital pin 8 on
    delay(100); // Waits for 100 ms
    cnt++;
    Serial.println(cnt);
  }
  
  else
  {
    digitalWrite(ledPin, LOW); // Sets the digital pin 8 off
    delay(100); //Waits for 100 ms
  }
}
