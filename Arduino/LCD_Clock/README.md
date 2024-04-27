## Interactive Arduino Wristwatch with Time Management and I2C LCD Display

This project builds a virtual wristwatch using an Arduino Uno, four buttons, and an I2C 16x2 LCD display.
Object-oriented programming concepts are implemented through two main classes: TimeManager and UserInterface.

**Components:**

* Arduino Uno
* Four buttons (Light, Mode, Start, Reset)
* I2C 16x2 LCD display
* Jumper wires
* Breadboard (optional)

**Functionality:**

1. **TimeManager Class:**
    * Keeps track of the current time (hours, minutes, seconds).
    * Provides methods to increment/decrement time values and handle overflow (e.g., going from 23:59 to 00:00).

2. **UserInterface Class:**
    * Manages user interaction with the four buttons.
    * Detects button presses and triggers corresponding actions in TimeManager.
        * **Light Button:** Switchs LCD display backlight on or off.
        * **Mode Button:** Cycles through different watch functionalities (e.g., time display, alarm setting system and time setting system).
        * **Start Button:** Initiates functions based on the current mode (e.g., switching between minutes and hours when setting alarm or syncing time).
        * **Reset Button:** Changes time values (e.g., hours or minutes in alarm setting or time syncing).

3. **Overall Program Flow:**
    * The program continuously monitors button presses using the UserInterface class.
    * When a button is pressed, the UserInterface class calls the appropriate TimeManager method to modify the time or trigger functionalities based on the current mode.
    * The current time is constantly formatted and displayed on the I2C LCD screen by the program.

**Benefits of Object-Oriented Design:**

* Improved code modularity and reusability.
* Easier maintenance and future modifications.
* Clear separation of concerns between timekeeping logic and user interaction.

**Learning Objectives:**

* Understand object-oriented programming concepts (classes, objects, methods).
* Apply object-oriented design to manage complex functionalities in Arduino projects.
* Explore user interaction techniques with buttons in Arduino.
* Implement I2C communication protocol for LCD displays.
* Design custom classes for specific functionalities like Stopwatch or Timer.

**Diagram**
![](https://github.com/MI-Thierry/L4Internaship/blob/main/Arduino/LCD_Clock/LCD_Clock%20sketck.png)
