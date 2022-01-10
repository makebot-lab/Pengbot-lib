/* makebot pengbot library
 * makebot homepage : https://makebot.ml
 * lib-files : https://github.com/makebot-lab/pengbot-lib
 * developed by WONDAEHAN.
 */
#ifndef Pengbot_h
#define Pengbot_h

#include <Servo.h>
#include <Oscillator.h>
#include <US.h>
#include "Arduino.h"

class Pengbot {
  public:
    void ready();
    void attachservo(int x);
    void detachservo(int x);
    float distance();
    void stop();
    void forward(int speed);
    void backward(int speed);
    void turnleft(int speed);
    void turnright(int speed);
    void setleft(int angle);
    void setright(int angle);
    void sound(int soundnum);
  private:
    Oscillator servo[2];
    US us;
};

#endif
