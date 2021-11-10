# NinjaCat-LaserTower
Ninja Cat is a robot laser toy that randomly moves a servo tower on the X and Y
axis and lights up an attached laser to train your cat to be a ninja.
This project is powered by an Arduino Uno.
## The Build
Follow these instructions to get your cat training in no time!
1. Assemble the pan/tilt servo module:

  - [Pan/Tilt Assembly](https://learn.adafruit.com/mini-pan-tilt-kit-assembly/getting-started) - by Adafruit


2. The Altoids tin:
  - Cut out a port to fit the Arduino's USB connector
  - Cut out a slot for servo and laser wires
  - Mount the pan/tilt module to the lid of the tin


3. Wiring:

  - Connect the laser diode (w/ resistor) to ground (GND) pin and pin 13 on the Arduino (Diagram below)
  - Add a resistor between the laser and the Arduino. This limits current through the laser diode thus thus increasing the laser's lifespan. (resistor is already installed if you ordered the no-tools kit)
  - Connect the Arduino's 5v pin to x and y servo power (red servo wire) in series. (Or use the pre-spliced power cable included in the no-tools kit) 
  - Ground (GND) to x-servo and y-servo in series (black servo wire)
  - x-servo to pin 6 (yellow)
  - y-servo to pin 9 (yellow)_

![Wiring Diagram](pictures/NinjaCat-Wiring.png)

4. The program:
  - Open laserTower.ino in the Arduino IDE or [use the online editor](https://create.arduino.cc/editor)
  - Upload the program to the board
  - Modify these values based on the size of your ninja training grounds and the fitness level of your cat. You can start with the default values and adjust them as needed.
  ```c
  #define MIN_X 10        // X-servo angle range [MIN_X, MAX_X]
  #define MAX_X 90      
  #define MIN_Y 0         // Y-servo angle range [MIN_Y, MAX_Y]
  #define MAX_Y 40
  #define MIN_MOVE 10      // smallest move distance allowed
  #define MIN_FREEZE 100   // delay between moves range [MIN_FREEZE, MAX_FREEZE]
  #define MAX_FREEZE 1500
  #define MIN_MOVE_TIME 20 // time it takes servos to move to next position range [MIN_MOVE_TIME, MAX_MOVE_TIME]
  #define MAX_MOVE_TIME 50
  ```
  - Save and re-upload! Once you're satisfied, you can disconnect the board from your computer and power the laser tower from any outlet.
 
### Challenge question:
Now that you've finished the build, take a moment to go through the code and try to figure out the purpose of each line.
Can you guess the minimum and maximum values you can set for MIN_X, MAX_X, MIN_Y, MAX_Y? 
Once you have a guess, put in your values and see if you were right! Dont worry about breaking anything, if the servo tower makes weird noises just unplug it, fix your values, and try again!

### Happy Ninja-Cat Training!
![Wiring Diagram](pictures/NinjaCat_1.jpg)
![Wiring Diagram](pictures/NinjaCat_2.jpg)
