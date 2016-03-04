/* PWM信号                       */
int ledPin = 9;      // LEDはピン9に接続
int duty = 0;      //0-255の間でデューティ比を決める

void setup() { }

void loop() {
  if (duty < 255){
    analogWrite(ledPin, duty);   //PWM出力
    delay(50);
    duty += 1;                   //明るさ追加
  }else{
    duty = 0;                    //255で明るさリセット
  }
}
