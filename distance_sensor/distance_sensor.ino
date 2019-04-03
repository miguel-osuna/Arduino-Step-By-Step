/*
  Distance Sensor Test
  
  Describe what it does in layman's terms.  Refer to the components
  attached to the various pins:
  This programs allows to detect the distance between the sensor and an object
  
  Trigger Asigned to Pin 13
  Echo Asigned to Pin 12

  The circuit: 
  1 Distance Sensor

  Created 7/3/19
  By Miguel Osuna
  Modified: -/-/-
  By: -----------
*/

const int trigPin = 13;
const int echoPin = 12;

void setup()
{
  //We set up Trigger Pin as an Output and Echo Pin as an Input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Serial.print("Detecting...");
}

void loop()
{
  int timeDuration, distance;
  
  //First, we setup everything for the trigger square signal
  //The square signal has to have a length of 10 us in order to start the sensing
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //Start to take time when goes from LOW to HIGH, and stops counting until reaches LOW again.
  timeDuration = pulseIn(echoPin, HIGH);
  
  //We convert to cm, multiplying us * cm/us
  //The time needs to be divided by 2, because it's only one distance
  distance = (timeDuration / 2) / 29.1;

  if(distance < 0 || distance >= 200)
    Serial.println("Out of range...");
  else
  {
    Serial.print(distance);
    Serial.println("cm");
  }

  delay(500);
}

