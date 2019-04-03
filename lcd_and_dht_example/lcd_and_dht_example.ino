/*
  Purpose: This program prints the value that the DHT11 Humidity Sensor returs to the LCD.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2

 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 
 * DHT11 atached to pin 6

 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 * 
*/

// Include the library code:
#include <LiquidCrystal.h>
#include "DHT.h"

// Initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
// And we also define the correct humidity sensor with its pin
#define rsPin 12
#define enPin 11
#define d4Pin 5
#define d5Pin 4
#define d6Pin 3
#define d7Pin 2

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a  5.1kOhms resistor from pin 2 (data) to pin 1 (power) of the sensor
#define DHTPIN 6
#define DHTTYPE DHT11 //Sensor: DHT11 Humidity Sensor

LiquidCrystal lcd(rsPin, enPin, d4Pin, d5Pin, d6Pin, d7Pin);
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  dht.begin();
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Starting sensor...");
}

void loop() 
{
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  if(isnan(h) || isnan(t) || isnan(f))
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Failed to read");
    lcd.setCursor(0,1);
    lcd.print("from sesor");
  }

  lcd.clear();
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  //Top row
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("*C");

  //Bottom row
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%");  
}

