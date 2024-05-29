## Arduino Traffic Light Simulator with RGB LEDs

This project is a fun and educational introduction to Arduino programming and controlling LEDs. We'll build a miniature traffic light simulation using an Arduino Uno and three RGB LEDs (Red, Green, Yellow).
The program cycles through the classic traffic light sequence (red, yellow, green) to mimic real-world traffic signals.

**Components:**

* Arduino Uno (or compatible board)
* Three RGB LEDs (common cathode or common anode)
* Resistors (values depend on chosen LEDs - typically 220 ohms)
* Breadboard (optional)
* Jumper wires

**Functionality:**

1. The Arduino controls each color of the RGB LED by adjusting the voltage applied to its red, green, and blue pins. By varying the voltage on each pin, we can create different color combinations.
2. The program defines three separate colors for red, yellow (combination of red and green), and green.
3. It then uses a loop to cycle through these colors with specific delays to represent the duration of each traffic light state (red, yellow, green).

**Learning Objectives:**

* Understand the basic principles of controlling RGB LEDs with Arduino.
* Learn how to write code to manipulate individual LED colors.
* Explore using loops and delays to create timed sequences.
* Gain practical experience with basic circuit building using resistors and LEDs.

**Further Enhancements:**

* Modify the timing of each light state (red, yellow, green) to adjust the traffic light simulation.
* Add a pedestrian button that triggers a temporary change in the sequence (e.g., flashing red for stop, solid green for walk).
* Expand the project to include additional LEDs for pedestrian signals or turn arrows.

**Diagram**
![](https://github.com/MI-Thierry/L4Internaship/blob/main/Embedded%20system/Arduino/Traffic_lights/Traffic%20lights%20sketch.png)
