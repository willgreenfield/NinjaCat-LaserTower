/*
   laserTower.ino
   
   Ninja Cat - a robot laser-tower toy that randomly moves a servo tower on the X and Y axis 
   and lights up an attached laser to train your cat to be a ninja.
   
   HOW IT WORKS:
   The program loops, randomly choosing an (X,Y) position for the laser to point within  
   a defined boundary (play space). New positions are checked to be greater than "MIN_MOVE" 
   from the old position and the laser stays still for a random time between "MIN_FREEZE"
   and "MAX_FREEZE" to simulate a real bug flying around and landing.

   Created 26 Oct 2018 by William Greenfield
 */

 #include <Servo.h>

/* MODIFY THESE IF YOU WANT */



 #define MIN_X 10        // X-servo angle range [MIN_X, MAX_X]
 #define MAX_X 90      
 #define MIN_Y 0         // Y-servo angle range [MIN_Y, MAX_Y]
 #define MAX_Y 40
 #define MIN_MOVE 10      // smallest distance allowed for a new location from the current position
 #define MIN_FREEZE 100   // time to wait until next move
 #define MAX_FREEZE 1500
 #define MIN_MOVE_TIME 20 // time it takes the servos to move to new position 
 #define MAX_MOVE_TIME 50

/* CODE BELOW THIS LINE SHOULDNT NEED MODIFICATION */

 float rand_freeze; //random time between moves
 float x_pos = MIN_X + (MAX_X - MIN_X) / 2; //center of laser range
 float y_pos = MIN_Y + (MAX_Y - MIN_Y) / 2;
 float x_old = x_pos;
 float y_old = y_pos;
 float x_new;
 float y_new;

 float move_time; //duration of a move
 float x_velocity;
 float y_velocity;
 int i; //loop counter

// Instantiating servos
Servo X_Servo;
Servo Y_Servo;

void setup(){
  X_Servo.attach(6); // X-servo to pin 6
  Y_Servo.attach(9); // Y-servo to pin 9
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  //Write starting position to servos
  X_Servo.write(x_pos);
  Y_Servo.write(y_pos);  
}

void loop(){
  rand_freeze = random(MIN_FREEZE, MAX_FREEZE);
  move_time = random(MIN_MOVE_TIME,MAX_MOVE_TIME);
  x_new = random(MIN_X + MIN_MOVE, MAX_X - MIN_MOVE);
  y_new = random(MIN_Y + MIN_MOVE, MAX_Y - MIN_MOVE);

//checks that abs(x_new) is greater than MIN_MOVE. If not, add or subtract MIN_MOVE 
  if(abs(x_new - x_old) < MIN_MOVE){
    if(x_new > x_old)
      x_new += MIN_MOVE;
    else if(x_new < x_old)
      x_new -= MIN_MOVE;  
  }

//checks that abs(y_new) is greater than MIN_MOVE. If not, add or subtract MIN_MOVE 
  if(abs(y_new - y_old) < MIN_MOVE){
    if(y_new > y_old)
      y_new += MIN_MOVE;
    else if(y_new < y_old)
      y_new -= MIN_MOVE;  
  }

  //divide distance by move_time to determine a "velocity"
  x_velocity = (x_new - x_old) / move_time;
  y_velocity = (y_new - y_old) / move_time;

  //increment position by "velocity"
  for (i=0; i < move_time; i++) { 
      x_pos += x_velocity;
      y_pos += y_velocity;
      X_Servo.write(x_pos);  
      Y_Servo.write(y_pos);                    
      delay(10); 
  }

  //updates old positions 
  x_old = x_new;
  y_old = y_new;

  //delay beofore moving to next position
  delay(rand_freeze);
  

}

 
   
