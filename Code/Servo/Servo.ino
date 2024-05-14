#include <Servo.h>
Servo s1;
Servo s2;                          // create servo object to control a servo
Servo s3;                          // create servo object to control a servo                          
Servo s4;                          // create servo object to control a servo
int posn = 0;                      // variable to store the servo position
void setup()
{
  s1.attach (2);      // attaches the servo on pin 9 to the servo object
  s2.attach (3);      // attaches the servo on pin 9 to the servo object
  s3.attach (6);      // attaches the servo on pin 9 to the servo object
  s4.attach (5);      // attaches the servo on pin 9 to the servo object
}
void loop()
{
  for (posn = 90; posn < 180; posn += 1)            // goes from 0 degrees to 180 degrees
 {                                                                       // in steps of 1 degree
    s1.write (posn);                                                 // tell servo to go to position in variable 'pos'
    s2.write (posn);                                                 // tell servo to go to position in variable 'pos'
    s3.write (posn);                                                 // tell servo to go to position in variable 'pos'
    s4.write (posn); 
    delay (10);                                       // waits 10ms for the servo to reach the position
  }
  for (posn = 180; posn>=90; posn-=1)                // goes from 180 degrees to 0 degrees                                                                                 // in steps of 1 degree
{                               
    s1.write (posn);                                                 // tell servo to go to position in variable 'pos'
    s2.write (posn);                                                 // tell servo to go to position in variable 'pos'
    s3.write (posn);                                                 // tell servo to go to position in variable 'pos'
    s4.write (posn); 
    delay (10);                                        // waits 10ms for the servo to reach the position
  }
}