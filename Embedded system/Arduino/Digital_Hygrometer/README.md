## Arduino Humidity Monitor with I2C LCD Display

This project creates a digital humidity monitor using an Arduino Uno, a DHT11 sensor, and a 16x2 LCD display with an I2C interface. The DHT11 sensor detects the surrounding air's moisture level, and the Arduino translates that data into a humidity percentage displayed on the LCD screen.

**Components:**

* Arduino Uno
* DHT11 Sensor
* I2C 16x2 LCD Display
* Jumper wires
* Breadboard (optional)

**Functionality:**

1. The DHT11 sensor continuously measures the humidity in the environment.
2. The Arduino communicates with the DHT11 sensor through a single data pin.
3. Using a specific library, the Arduino retrieves the humidity data from the sensor.
4. The retrieved humidity value is then formatted and displayed on the first line of the I2C LCD.
5. You can customize the display to show additional information, like "Humidity: " before the value. 

**Learning Objectives:**

* Understand the operation of DHT11 humidity sensors.
* Learn I2C communication protocol for LCD displays.
* Explore using libraries to simplify sensor communication with Arduino.
* Practice data formatting and displaying information on an LCD screen.

**Applications:**

* This project can be used to monitor humidity levels in homes, greenhouses, or other environments where moisture control is crucial.
* By adding features like temperature sensors and alarms, you can create a more comprehensive environmental monitoring system.

**Code Structure:**

The Arduino code for this project involves these key sections:

1. **Library Inclusion:** Include the necessary libraries for I2C communication with the LCD (`LiquidCrystal_I2C.h`) and DHT sensor communication (`DHT.h`). 
2. **Pin Definitions:** Define the data pin connected to the DHT11 sensor and the I2C address of the LCD display.
3. **Setup Function:** This function initializes the I2C communication and configures the LCD display size (16 characters, 2 rows).
4. **Main Loop:** This loop continuously executes:
    * Reads humidity data from the DHT11 sensor using the library functions.
    * Formats the humidity value as a percentage (e.g., "55%").
    * Clears the first line of the LCD display.
    * Displays the formatted humidity data on the first line.

**Diagram**
![](https://github.com/MI-Thierry/L4Internaship/blob/main/Embedded%20system/Arduino/Digital_Hygrometer/Digital%20Hygrometer.png)
