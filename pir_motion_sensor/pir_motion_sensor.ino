/*
  PIR Sensor Test

  Describe what it does in layman's terms.  Refer to the components
  attached to the various pins:
  The program Turns On an LED when detecting movement 
  
  PIR Motion Sensor Asigned to Pin 7
  LED Asigned to Pin 6

  The circuit: 
  1 PIR Sensor
  1 Resistor
  1 LED

  Created 6/3/19
  By Miguel Osuna
  Modified: -/-/-
  By: -----------
*/
#define PIRPIN 7
#define LEDPIN 6

//The time we give to the sensor to calibrate (10 - 60 seconds according to the datasheet)
int calibrationTime = 30;

//We consider there is no movement at the begining
int movementState = LOW;

//If the sensor senses LOW, remain HIGH during specified miliseconds
int misSecAfterLow = 5000; //5 seconds
long unsigned int timeTurnedLow;

void setup()
{
	//Set the Motion Sensor as a Digital Input
	//In this case, is not floated, there is always a value
	pinMode(PIRPIN, INPUT);
	digitalWrite(PIRPIN, LOW);

	//Set the LED as a Digital Output
	pinMode(LEDPIN, OUTPUT);
	digitalWrite(LEDPIN, LOW);

	Serial.begin(9600);
	Serial.println("Warming up motion sensor...\t");

	delay(calibrationTime * 1000);
	Serial.println("Sensor active");
}

void loop()
{
	//It reads a digital value: '1' or '0'
	int sense = digitalRead(PIRPIN);

	if(sense == HIGH)
	{
		digitalWrite(LEDPIN, HIGH);

		//With this it will print just once, if there's still movement.
		if(movementState == LOW)
		{
			Serial.println("Movement detected!");
			movementState = HIGH;
		}
	}

	else
	{

		if(movementState == HIGH)
		{
			Serial.println("Movement not detected!");
			movementState = LOW;
			//Take the miliseconds the moment the state went LOW
			timeTurnedLow = millis();
		}
	}

	 //This block checks to see if enough time has passed after the PRI went LOW.
  	//If yes, and assuming that the PIR sensor did not go HIGH again, turn off the LED
  	if(!movementState && (millis() - timeTurnedLow) > minSecAfterPIRLow)
  	{
    	Serial.println("Extended time HIGH ended!");   
    	digitalWrite(ledPin, LOW); // turn LED OFF  
    }


	delay(1000);
}