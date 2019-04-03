#define thermistorPin A0
#define RIN 15000

void setup()
{
	pinMode(thermistorPin, INPUT);
	Serial.begin(9600);
}

void loop()
{
	float reading;

	reading = analogRead(thermistorPin);

	Serial.print("Analog reading: ");
	Serial.print(reading);

	//Convert the value to resistance
	reading = (1023 / reading) - 1;
	reading = RIN / reading;
  Serial.print("\t");
	Serial.print("Thermistor resistance: ");
	Serial.println(reading);

	delay(1000);
}
