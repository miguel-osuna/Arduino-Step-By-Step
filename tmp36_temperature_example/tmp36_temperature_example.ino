/*
  TMP36 Sensor Test

  Describe what it does in layman's terms.  Refer to the components
  attached to the various pins:
  The programs read the input from the sensor and displays the temperature in the serial monitor
  
  TMP36 Sensor asigned to AO as Input

  The circuit: 
  1 TMP36 Sensor

  Created 3/2/19
  By Miguel Osuna
  Modified: -/-/-
  By: -----------
*/
#define TMP36PIN A0
#define OFFSET 0.01 //10 mV/°C

//The pin used was A0, if yours its different, change it.
const int tmp36Pin = A0;

//Uncomment the supply voltage you're using for your circuit.
const float supplyVoltage = 5.0; 
//cont float supplyVoltage = 3.3

void setup()
{
    //analogReference(EXTERNAL); //If you use a 3.3V supply voltage as a reference for the pin AREF, uncomment this line
                               //If you are using a 5V supply, ignore it.
    pinMode(TMP36PIN, INPUT);
    Serial.begin(9600);  
}

void loop()
{
    float temperature;
    float reading = analogRead(tmp36Pin);
    
    reading = reading * supplyVoltage / 1024;
    Serial.print("The voltage read was: ");
    Serial.print(reading);

    reading -= 0.5;
    temperature = reading / OFFSET;
    Serial.print("\t\t");
    Serial.print("The temperature is: ");
    Serial.print(temperature);
    Serial.println("°C\t");

    delay(5000);
}

