int ledPin = 8;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop() 
{
  int i;
  Serial.println("This is the following message: ");
  for(i = 0; i < 3; i++)
    shortMessage();

   for(i = 0; i < 3; i++)
    longMessage();

   for(i = 0; i < 3; i++)
    shortMessage();

   delay(2000);
}

void shortMessage(void)
{
  digitalWrite(ledPin, HIGH);
  delay(400);
  digitalWrite(ledPin, LOW);
  delay(400);
}

void longMessage(void)
{
  digitalWrite(ledPin, HIGH);
  delay(800);
  digitalWrite(ledPin, LOW);
  delay(800);
}

