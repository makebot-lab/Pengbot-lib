/*makebot R BOT library
 * makebot homepage : https://makebot.ml
 * lib-files : https://github.com/makebot-lab/rbot-lib
 * R BOT is humanoid robot developed by WONDAEHAN.
 */
#ifndef Rbot_h
#define Rbot_h

#include <Servo.h>
#include <Oscillator.h>
#include <US.h>
#include "Arduino.h"

class Rbot {
  public:
    void ready();
    void attachservo(int x);
    void detachservo(int x);
    void setangles(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
    float distance();
    void oscillateServos(int A[4], int O[4], int T, double phase_diff[4], float cycle);
    void home();
    void move(int movenum);
    void motion(int motionnum);
    void sound(int soundnum);
  private:
    Oscillator servo[10];
    US us;
    int servo_position[4];
    void _execute(int A[4], int O[4], int T, double phase_diff[4], float steps);
};

#endif
