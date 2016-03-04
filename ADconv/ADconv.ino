/* A/D変換                */
/* センサーの値を読み取る   */

int ledPin = 13;          // LEDをデジタルピン13に接続
int analogPin = 3;        // ここにセンサーを接続
int val = 0;              // 読み取った値を格納する変数
int threshold = 512;      // しきい値

void setup(){
  pinMode(ledPin, OUTPUT);   // ピン13を出力に設定
}

void loop(){
  val = analogRead(analogPin);    // アナログピンを読み取る
  if (val >= threshold){
    digitalWrite(ledPin, HIGH);   // LEDをオンに
  } else {
    digitalWrite(ledPin, LOW);    // LEDをオフに
  }
}
