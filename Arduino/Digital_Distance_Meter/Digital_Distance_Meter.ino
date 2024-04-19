#include <LiquidCrystal_I2C.h>

int TrigPin = 8;
int EchoPin = 9;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  int duration = pulseIn(EchoPin, HIGH);
  // 0.034 cm/us is the speed of sound and distance = speed * time
  // We will divid by 2 because, we're measuring round trip time.
  int distance = (0.034 * duration)/2;
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance to obstacle is:");
  
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print(" cm");
}
