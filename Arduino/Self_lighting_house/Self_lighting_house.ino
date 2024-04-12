int  LIDRPin = A0;
int LEDPin = 13;
int Counter = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(LIDRPin, INPUT);
  pinMode(LEDPin, OUTPUT);
}

void loop()
{
  int lightIntensity = analogRead(LIDRPin);
  if (lightIntensity < 15) {
    if (Counter > 5) {
      digitalWrite(LEDPin, LOW);
    }
    Counter++;
  }
  else
  {
    digitalWrite(LEDPin, HIGH);
    Counter = 0;
  }
}

