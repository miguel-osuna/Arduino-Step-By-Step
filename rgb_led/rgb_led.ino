/*
  Analog and Digital Pins Test

  Describe what it does in layman's terms.  Refer to the components
  attached to the various pins:
  The programs Turns On an LED with the PWM analog output by changing the potentiometer position and by pressing the push-button.
  
  Red LED asinged to Pin 8
  Green LED asigned to Pin 5
  Blue LED asigned to Pin 6
  Push-button asigned to Pin 7

  The circuit: 
  1 RGB
  1 Push-button
  1 Resistor

  Created 2/28/19
  By Miguel Osuna
  Modified: -/-/-
  By: -----------
*/

#define redPin 9
#define greenPin 5 
#define bluePin 6
#define buttonPin 7

void setup()
{
	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);
	pinMode(buttonPin, INPUT_PULLUP); //because of the Internal Pull-up resistor, unpressed = HIGH

	digitalWrite(redPin, LOW);
	digitalWrite(greenPin, LOW);
	digitalWrite(bluePin, LOW);
}

void loop()
{
	int buttonState;
	int value = 255; //Range from 0 to 255

	buttonState = digitalRead(buttonPin);

	//redColor(value);
	//greenColor(value);
	//blueColor(value);
	yellowColor(value);
	//magentaColor(value);
	//cyanColor(value);

	if(buttonState == LOW) //Turn off the colors in orden when the button is pressed
	{
		turnOff(bluePin);
		turnOff(greenPin);
		turnOff(redPin);
	}
}

void redColor(int value)
{
	digitalWrite(redPin, value);
}

void greenColor(int value)
{
	digitalWrite(greenPin, value);
}

void blueColor(int value)
{
	digitalWrite(bluePin, value);
}

void yellowColor(int value)
{
	digitalWrite(redPin, value);
	digitalWrite(greenPin, value);
}

void magentaColor(int value)
{
	digitalWrite(redPin, value);
	digitalWrite(bluePin, value);
}

void cyanColor(int value)
{
	digitalWrite(greenPin, value);
	digitalWrite(bluePin, value);
}

void turnOff(int pin)
{
	digitalWrite(pin, LOW);
}