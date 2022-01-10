/*makebot R BOT library
 * makebot homepage : https://makebot.ml
 * lib-files : https://github.com/makebot-lab/rbot-lib
 * R BOT is humanoid robot developed by WONDAEHAN.
 */
#include "Arduino.h"
#include "Rbot.h"
#include <Servo.h>

//servos
void Rbot::attachservo(int x) {
  servo[x].attach(x + 2);
}

void Rbot::detachservo(int x) {
  servo[x].attach(x + 2);
  servo[x].detach();
}

void Rbot::_execute(int A[4], int O[4], int T, double phase_diff[4], float steps = 1.0){
  int cycles=(int)steps;
  if (cycles >= 1) 
    for(int i = 0; i < cycles; i++) 
      oscillateServos(A,O, T, phase_diff, 1);
  oscillateServos(A,O, T, phase_diff,(float)steps-cycles);
}

void Rbot::oscillateServos(int A[4], int O[4], int T, double phase_diff[4], float cycle){
  for (int i=0; i<4; i++) {
    servo[i].SetO(O[i]);
    servo[i].SetA(A[i]);
    servo[i].SetT(T);
    servo[i].SetPh(phase_diff[i]);
  }
  double ref=millis();
   for (double x=ref; x<=T*cycle+ref; x=millis()){
     for (int i=0; i<4; i++){
        servo[i].refresh();
     }
  }
}

void Rbot::setangles(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
  for(int x = 0; x < 10; x++) {
    if(x == 0) {
      if(a <= 180) {
        servo[x].SetPosition(a);
      }
    }else if(x == 1) {
      if(b <= 180) {
        servo[x].SetPosition(b);
      }
    }else if(x == 2) {
      if(c <= 180) {
        servo[x].SetPosition(c);
      }
    }else if(x == 3) {
      if(d <= 180) {
        servo[x].SetPosition(d);
      }
    }else if(x == 4) {
      if(e <= 180) {
        servo[x].SetPosition(e);
      }
    }else if(x == 5) {
      if(f <= 180) {
        servo[x].SetPosition(f);
      }
    }else if(x == 6) {
      if(g <= 180) {
        servo[x].SetPosition(g);
      }
    }else if(x == 7) {
      if(h <= 180) {
        servo[x].SetPosition(h);
      }
    }else if(x == 8) {
      if(i <= 180) {
        servo[x].SetPosition(i);
      }
    }else if(x == 9) {
      if(j <= 180) {
        servo[x].SetPosition(j);
      }
    }
  }
}

//sensor
float Rbot::distance(){

  return us.read();
}

//R BOT
void Rbot::ready() {  //ready
  for(int x = 0; x < 10; x++) {
    attachservo(x);
    delay(30);
  }
  noTone(13);
  us.init(A0, A1);
  home();
}

void Rbot::home() {  //home
  setangles(90, 90, 90, 90, 90, 90, 0, 180, 90, 90);
}

void Rbot::move(int movenum) {  //move
  if(movenum == 1) {  //forward
    int A[4]= {30, 30, 20, 20};
    int O[4] = {0, 0, 4, -4};
    double phase_diff[4] = {0, 0, DEG2RAD(-90), DEG2RAD(-90)};
    _execute(A, O, 1000, phase_diff, 1);
  }else if(movenum == 2) {  //backward
    int A[4]= {30, 30, 20, 20};
    int O[4] = {0, 0, 4, -4};
    double phase_diff[4] = {0, 0, DEG2RAD(90), DEG2RAD(90)};
    _execute(A, O, 1000, phase_diff, 1);
  }else if(movenum == 3) {  //turn left
    int A[4]= {30, 10, 20, 20};
    int O[4] = {0, 0, 4, -4};
    double phase_diff[4] = {0, 0, DEG2RAD(-90), DEG2RAD(-90)}; 
    _execute(A, O, 1000, phase_diff, 1);
  }else if(movenum == 4) {  //turn right
    int A[4]= {10, 30, 20, 20};
    int O[4] = {0, 0, 4, -4};
    double phase_diff[4] = {0, 0, DEG2RAD(-90), DEG2RAD(-90)}; 
    _execute(A, O, 1000, phase_diff, 1);
  }
  home();
}

void Rbot::motion(int motionnum) {  //motion
  if(motionnum == 1) { //hello1
    setangles(181, 181, 181, 181, 181, 181, 181, 0, 181, 181);
    delay(300);
    setangles(181, 181, 181, 181, 181, 181, 181, 45, 181, 181);
    delay(300);
    setangles(181, 181, 181, 181, 181, 181, 181, 0, 181, 181);
    delay(300);
    setangles(181, 181, 181, 181, 181, 181, 181, 45, 181, 181);
    delay(300);
    setangles(181, 181, 181, 181, 181, 181, 181, 0, 181, 181);
    delay(300);
    setangles(181, 181, 181, 181, 181, 181, 181, 45, 181, 181);
    delay(500);
    setangles(181, 181, 181, 181, 181, 181, 181, 180, 181, 181);
  }else if(motionnum == 2) { //hello2
    setangles(181, 181, 181, 181, 181, 181, 180, 0, 181, 181);
    delay(300);
    setangles(181, 181, 181, 181, 181, 181, 135, 45, 181, 181);
    delay(300);
    setangles(181, 181, 181, 181, 181, 181, 180, 0, 181, 181);
    delay(300);
    setangles(181, 181, 181, 181, 181, 181, 135, 45, 181, 181);
    delay(300);
    setangles(181, 181, 181, 181, 181, 181, 180, 0, 181, 181);
    delay(300);
    setangles(181, 181, 181, 181, 181, 181, 135, 45, 181, 181);
    delay(500);
    setangles(181, 181, 181, 181, 181, 181, 0, 180, 181, 181);
  }else if(motionnum == 3) { //jump
    setangles(181, 181, 90, 90, 181, 181, 90, 90, 120, 60);
    delay(300);
    setangles(181, 181, 135, 45, 181, 181, 135, 45, 90, 90);
    delay(300);
    setangles(181, 181, 90, 90, 181, 181, 90, 90, 120, 60);
    delay(300);
    setangles(181, 181, 135, 45, 181, 181, 135, 45, 90, 90);
    delay(300);
    setangles(181, 181, 90, 90, 181, 181, 90, 90, 120, 60);
    delay(300);
    setangles(181, 181, 135, 45, 181, 181, 135, 45, 90, 90);
    delay(300);
    setangles(181, 181, 90, 90, 181, 181, 0, 180, 181, 181);
  }else if(motionnum == 4) { //standup
    setangles(181, 181, 120, 60, 181, 181, 135, 45, 181, 181);
    delay(300);
    setangles(181, 181, 90, 90, 181, 181, 0, 180, 181, 181);
  }else if(motionnum == 5) { //icanfly
    setangles(181, 181, 110, 70, 181, 181, 45, 135, 181, 181);
    delay(150);
    setangles(181, 181, 135, 45, 181, 181, 90, 90, 181, 181);
    delay(150);
    setangles(181, 181, 181, 181, 181, 181, 135, 45, 181, 181);
    delay(300);
    setangles(181, 181, 181, 181, 181, 181, 160, 20, 181, 181);
    delay(300);
    setangles(181, 181, 181, 181, 181, 181, 135, 45, 181, 181);
    delay(300);
    setangles(181, 181, 181, 181, 181, 181, 160, 20, 181, 181);
    delay(300);
    setangles(181, 181, 181, 181, 181, 181, 135, 45, 181, 181);
    delay(300);
    setangles(181, 181, 181, 181, 181, 181, 160, 20, 181, 181);
    delay(500);
    setangles(181, 181, 90, 90, 181, 181, 0, 180, 181, 181);
  }else if(motionnum == 6) { //penguin
    setangles(181, 181, 75, 181, 75, 75, 20, 160, 181, 181);
    delay(300);
    setangles(181, 181, 90, 105, 105, 105, 20, 160, 181, 181);
    delay(300);
    setangles(181, 181, 75, 90, 75, 75, 20, 160, 181, 181);
    delay(300);
    setangles(181, 181, 90, 105, 105, 105, 20, 160, 181, 181);
    delay(300);
    setangles(181, 181, 75, 90, 75, 75, 20, 160, 181, 181);
    delay(300);
    setangles(181, 181, 90, 105, 105, 105, 20, 160, 181, 181);
    delay(300);
    setangles(181, 181, 75, 90, 75, 75, 20, 160, 181, 181);
    delay(300);
    setangles(181, 181, 90, 105, 105, 105, 20, 160, 181, 181);
    delay(300);
    setangles(181, 181, 181, 90, 90, 90, 0, 180, 181, 181);
  }else if(motionnum == 7) { //yay
    setangles(181, 181, 181, 181, 181, 181, 45, 135, 181, 181);
    delay(150);
    setangles(181, 181, 181, 181, 181, 181, 90, 90, 181, 181);
    delay(150);
    setangles(181, 181, 75, 90, 181, 181, 135, 10, 181, 181);
    delay(300);
    setangles(181, 181, 90, 105, 181, 181, 170, 45, 181, 181);
    delay(300);
    setangles(181, 181, 75, 90, 181, 181, 135, 10, 181, 181);
    delay(300);
    setangles(181, 181, 90, 105, 181, 181, 170, 45, 181, 181);
    delay(300);
    setangles(181, 181, 75, 90, 181, 181, 135, 10, 181, 181);
    delay(300);
    setangles(181, 181, 90, 105, 181, 181, 170, 45, 181, 181);
    delay(300);
    setangles(181, 181, 75, 90, 181, 181, 135, 10, 181, 181);
    delay(300);
    setangles(181, 181, 90, 105, 181, 181, 170, 45, 181, 181);
    delay(300);
    setangles(181, 181, 181, 90, 181, 181, 0, 180, 181, 181);
  }else if(motionnum == 8) { //sitdown
    setangles(181, 181, 0, 180, 181, 181, 90, 90, 181, 181);
    delay(2500);
    setangles(181, 181, 90, 90, 181, 181, 0, 180, 181, 181);
  }else if(motionnum == 9) { //yes
    setangles(181, 181, 181, 181, 181, 181, 0, 0, 181, 181);
    delay(2500);
    setangles(181, 181, 181, 181, 181, 181, 0, 180, 181, 181);
  }else if(motionnum == 10) { //no
    setangles(45, 45, 181, 181, 181, 181, 135, 45, 181, 181);
    delay(300);
    setangles(135, 135, 181, 181, 181, 181, 181, 181, 181, 181);
    delay(300);
    setangles(45, 45, 181, 181, 181, 181, 181, 181, 181, 181);
    delay(300);
    setangles(135, 135, 181, 181, 181, 181, 181, 181, 181, 181);
    delay(300);
    setangles(90, 90, 181, 181, 181, 181, 0, 180, 181, 181);
  }else if(motionnum == 11) { //dance
    setangles(181, 181, 75, 181, 70, 70, 0, 20, 75, 181);
    delay(200);
    setangles(181, 181, 90, 105, 110, 110, 110, 0, 90, 105);
    delay(400);
    setangles(181, 181, 75, 90, 70, 70, 160, 180, 75, 90);
    delay(400);
    setangles(181, 181, 90, 105, 110, 110, 160, 180, 90, 105);
    delay(400);
    setangles(181, 181, 75, 90, 70, 70, 0, 20, 75, 181);
    delay(200);
    setangles(181, 181, 90, 105, 110, 110, 110, 0, 90, 105);
    delay(400);
    setangles(181, 181, 75, 90, 70, 70, 160, 180, 75, 90);
    delay(400);
    setangles(181, 181, 90, 105, 110, 110, 160, 180, 90, 105);
    delay(400);
    setangles(181, 181, 181, 90, 90, 90, 0, 180, 181, 90);
  }else if(motionnum == 12) { //handshake
    setangles(181, 181, 181, 181, 181, 180, 181, 181, 181, 181);
    delay(300);
    setangles(181, 181, 181, 181, 181, 150, 181, 181, 181, 181);
    delay(300);
    setangles(181, 181, 181, 181, 181, 180, 181, 181, 181, 181);
    delay(300);
    setangles(181, 181, 181, 181, 181, 150, 181, 181, 181, 181);
    delay(300);
    setangles(181, 181, 181, 181, 181, 90, 181, 181, 181, 181);
  }
  home();
}

void Rbot::sound(int soundnum) {  //sound
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
