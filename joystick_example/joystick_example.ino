/*
  Joystick Example
    
  This program displays in the serial port the resistance of both axis of the joystick

  Joystick Connections
  GND - Arduino GND
  +5V - Arduino Vcc (5V)
  VRx - A1
  VRy - A0
  SW - A2

  The circuit:  
  1 Joystick

  Created 16/3/19
  By Miguel Osuna
  Modified: -/-/-
  By: -----------
*/

//First we define the pins used

const int verticalAxis = A0;
const int horizontalAxis = A1;
const int selectButton = A2; //Used as digital 

void setup()
{
    //Just for being clear, we specify the pin modes
    pinMode(verticalAxis, INPUT);
    pinMode(horizontalAxis, INPUT);
    pinMode(selectButton, INPUT_PULLUP);
    Serial.begin(9600);
}

void loop()
{
    //We read the values of the potentiometer
    int horizontalValue = analogRead(horizontalAxis);
    int verticalValue = analogRead(verticalAxis);
    int select = digitalRead(selectButton);

    //We display the read values
    Serial.print("X-axis position: ");
    Serial.print(horizontalValue, DEC);
    Serial.print("  ");
    Serial.print("Y-axis position: ");
    Serial.print(verticalValue, DEC);
    Serial.print("  ");
    
    Serial.print("Button ");
    if(select == HIGH)
        Serial.println("not pressed");
    else
        Serial.println("pressed");
}

