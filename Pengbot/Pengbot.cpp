/*makebot pengbot library
 * makebot homepage : https://makebot.ml
 * lib-files : https://github.com/makebot-lab/pengbot-lib
 * developed by WONDAEHAN.
 */
#include "Arduino.h"
#include "Pengbot.h"
#include <Servo.h>

//servos
void Pengbot::attachservo(int x) {
  servo[x].attach(x + 2);
}

void Pengbot::detachservo(int x) {
  servo[x].attach(x + 2);
  servo[x].detach();
}

//sensor
float Pengbot::distance(){
  return us.read();
}

//pengbot
void Pengbot::ready() {  //ready
  for(int x = 0; x < 2; x++) {
    attachservo(x);
    delay(30);
  }
  noTone(13);
  us.init(A0, A1);
  stop();
}

void Pengbot::stop() {  //stop
  servo[0].SetPosition(90);
  servo[1].SetPosition(90);
}

void Pengbot::forward(int speed) {  //forward
  servo[0].SetPosition(90 + speed);
  servo[1].SetPosition(90 - speed);
}

void Pengbot::backward(int speed) {  //backward
  servo[0].SetPosition(90 - speed);
  servo[1].SetPosition(90 + speed);
}

void Pengbot::turnleft(int speed) {  //turn left
  servo[0].SetPosition(90 - speed);
  servo[1].SetPosition(90 - speed);
}

void Pengbot::turnright(int speed) {  //turn right
  servo[0].SetPosition(90 + speed);
  servo[1].SetPosition(90 + speed);
}

void Pengbot::setleft(int angle) {  //set left servo's angle
  servo[0].SetPosition(angle);
}

void Pengbot::setright(int angle) {  //set right servo's angle
  servo[1].SetPosition(angle);
}

void Pengbot::sound(int soundnum) {  //sound
  if(soundnum == 1) { //happy
    tone(13, 1300);
    delay(50);
    tone(13, 1125);
    delay(100);
    tone(13, 1500);
    delay(100);
    tone(13, 1700);
    delay(100);
  }else if(soundnum == 2) { //sad
    tone(13, 240);
    delay(100);
    noTone(13);
    delay(500);
    tone(13, 240);
    delay(200);
    noTone(13);
    delay(350);
    tone(13, 220);
    delay(400);
    noTone(13);
    delay(350);
    tone(13, 200);
    delay(400);
  }else if(soundnum == 3) { //surprised
    tone(13, 5000);
    delay(850);
  }else if(soundnum == 4) { //angry
    tone(13, 300);
    delay(200);
    tone(13, 100);
    delay(400);
  }else if(soundnum == 5) { //sleepy
    tone(13, 100);
    delay(800);
    noTone(13);
    delay(800);
    tone(13, 100);
    delay(800);
    noTone(13);
    delay(800);
    tone(13, 100);
    delay(800);
    noTone(13);
    delay(800);
    tone(13, 100);
    delay(800);
  }else if(soundnum == 6) { //joy
    tone(13, 1200);
    delay(100);
    tone(13, 1500);
    delay(100);
    tone(13, 1800);
    delay(300);
  }
  noTone(13);
}
