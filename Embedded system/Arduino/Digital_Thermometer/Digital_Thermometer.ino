// Remember to include Adafruit_Unified_Sensor-1.1.14 library.
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

int DHTDataPin = 2;

DHT dhtSensor(DHTDataPin, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  dhtSensor.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature = dhtSensor.readTemperature();

  lcd.clear();
  lcd.setCursor(0,0);
  // check if any reads failed
  if (isnan(temperature))
  {
    lcd.print("Failed to read from DHT11 sensor!");
  }
  else
  {
    lcd.print("Temperature: ");
    lcd.setCursor(0,1);
    lcd.print(temperature);
    lcd.print("°C");
  }
}
