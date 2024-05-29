## Arduino Temperature Monitor with I2C LCD Display

This project creates a simple yet informative temperature monitor using an Arduino Uno, a DHT11 sensor, and an I2C 16x2 LCD display.
The DHT11 sensor detects the surrounding air temperature, and the Arduino translates that data into a user-friendly display on the LCD screen.

**Components:**

* Arduino Uno
* DHT11 Sensor
* I2C 16x2 LCD Display
* Jumper wires
* Breadboard (optional)

**Functionality:**

1. The DHT11 sensor continuously measures the ambient temperature.
2. The Arduino communicates with the DHT11 sensor through a single data pin.
3. Using a specific library, the Arduino retrieves the temperature data from the sensor.
4. The retrieved temperature value is then formatted (including units, such as °C or °F) and displayed on the first line of the I2C LCD.
5. You can customize the display further to show additional information, like "Temperature: " before the value or a small icon representing hot or cold.

**Learning Objectives:**

* Understand the operation of DHT11 temperature sensors.
* Learn I2C communication protocol for LCD displays.
* Explore using libraries to simplify sensor communication with Arduino.
* Practice data formatting and displaying information on an LCD screen.

**Applications:**

* This project can be used to monitor room temperature for comfort control or to track temperature changes in greenhouses, storage units, or other environments where temperature is a crucial factor.
* By adding features like humidity sensors or alarms, you can create a more comprehensive environmental monitoring system.

**Code Structure:**

The Arduino code for this project involves these key sections:

1. **Library Inclusion:** Include the necessary libraries for I2C communication with the LCD (`LiquidCrystal_I2C.h`) and DHT sensor communication (`DHT.h`).
2. **Pin Definitions:** Define the data pin connected to the DHT11 sensor and the I2C address of the LCD display.
3. **Setup Function:** This function initializes the I2C communication and configures the LCD display size (16 columns, 2 rows).
4. **Main Loop:** This loop continuously executes:
    * Reads temperature data from the DHT11 sensor using the library functions.
    * Formats the temperature value with a chosen unit (°C or °F).
    * Clears the first line of the LCD display.
    * Displays the formatted temperature data on the first line.

**Diagram**
![](https://github.com/MI-Thierry/L4Internaship/blob/main/Embedded%20system/Arduino/Digital_Thermometer/Digital%20Thermometer.png)
