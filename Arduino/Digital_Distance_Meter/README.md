## Arduino Ultrasonic Distance Measurement with LCD Display

This project utilizes an Arduino Uno board, an ultrasonic sensor (HC-SR04), and a 16x2 LCD display to measure the distance between the sensor and an obstacle. The measured distance is then displayed on the LCD screen in real-time.

**Components:**

* Arduino Uno
* Ultrasonic Sensor (HC-SR04)
* 16x2 LCD display
* Jumper wires
* Breadboard (optional)

**Functionality:**

1. The ultrasonic sensor emits a high-frequency sound pulse.
2. This sound wave travels towards an obstacle and reflects back to the sensor.
3. The Arduino uses two digital pins to control the ultrasonic sensor:
    * **Trigger Pin:** Sends a short pulse to initiate the sound emission.
    * **Echo Pin:** Listens for the reflected sound wave and measures the time it takes to return.
4. Knowing the speed of sound (approximately 343 meters per second), the Arduino calculates the distance to the obstacle based on the following formula: `distance = (time * speed of sound) / 2` (We divide by 2 since the sound travels round trip)
5. The calculated distance is then displayed on the 16x2 LCD screen.

**Learning Objectives:**

* Understand the working principle of ultrasonic sensors.
* Learn how to interface an ultrasonic sensor with Arduino.
* Get familiar with using the Arduino IDE to write code for distance measurement.
* Explore basic LCD interfacing techniques with Arduino.

**Applications:**

* This project serves as a foundational step for building obstacle avoidance robots or proximity sensors. 
* It can be adapted for various applications requiring distance measurement, such as parking sensors or liquid level detectors (with modifications).

**Code Structure:**

The Arduino code for this project can be divided into three main sections:

1. **Library Inclusion:**  We'll include the `LiquidCrystal.h` library to control the LCD display.
2. **Pin Definitions:**  We'll define the digital pins connected to the trigger and echo pins of the ultrasonic sensor. We'll also define the LCD pins based on the connection method I2C.  
3. **Main Loop:**  This loop continuously executes the following steps:
    * Triggers the ultrasonic sensor to emit a sound pulse.
    * Measures the echo time.
    * Calculates the distance based on the formula mentioned earlier.
    * Clears the LCD screen and positions the cursor.
    * Displays the calculated distance on the LCD screen.

**Diagram:**
![](https://github.com/MI-Thierry/L4Internaship/blob/main/Arduino/Digital_Distance_Meter/Digital%20Distance%20meter%20sketch.png)
