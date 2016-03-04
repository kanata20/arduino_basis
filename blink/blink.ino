/* LEDチカチカ */

int led = 13;  //13番ピンがLEDにつながっているので，これを「led」と名付ける

/* setup()では，ピンの設定などを行う．*/
void setup() {                
  pinMode(led, OUTPUT); //ledと名付けたピンを，出力に設定
}

/* loop()内には，動作を書く．永遠にこの中身を繰り返してくれる */
void loop() {
  digitalWrite(led, HIGH);   // ピンledを「HIGH」状態にする．電圧が高くなる
  delay(1000);               // 1秒待つ
  digitalWrite(led, LOW);    // ピンledを「LOW」状態にする．電圧が高くなる
  delay(1000);               // 1秒待つ
}
