/*
  UV Sensor Test

  Describe what it does in layman's terms.  Refer to the components
  attached to the various pins:
  The programs prints the ultra violet index according the the uv sensor
  
  UV Sensor asigned to AO as Input

  The circuit: 
  1 UV Sensor

  Created 2/28/19
  By Miguel Osuna
  Modified: -/-/-
  By: -----------
*/

const int uvPin = A0;

void setup()
{
	pinMode(uvPin, INPUT);
	Serial.begin(9600);
}

void loop()
{
	//Read the sensor's input from the pin A0
	int sensorValue = analogRead(uvPin);
	
	//Define the UV Index Constant
	const int uvConst = 0.1;

	//Convert the reading from the input to a voltage
	float sensorVoltage = sensorValue * 5 / 1023;

	//Calculate the UV Index
	float uvIndex = sensorVoltage / uvConst;

	//Print out the results
	Serial.println("The sensor voltage is: ");
	Serial.print(sensorVoltage);
	Serial.print(",	");
	Serial.print("The UV Index is: ");
	Serial.print(uvIndex);
	delay(100);
}