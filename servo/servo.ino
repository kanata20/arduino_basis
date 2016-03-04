/* servo */

#include <Servo.h>    //Servo.hの読み込み

Servo myservo;        //Servo型のmyservoオブジェクトを作成

void setup() {
  myservo.attach(9);  //myservoの接続ピンを9番にする
}

void loop() {
   myservo.write(0);   //myservoの角度を0度に指定
   delay(1000);        //1秒待つ
   myservo.write(90);  //myservoの角度を90度に指定
   delay(1000);        //1秒待つ
}

