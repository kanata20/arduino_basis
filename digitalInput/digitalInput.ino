/* digital Input */

int ledPin = 13; // LEDを13番ピンに
int inPin = 7;   // デジタルピン7にプッシュボタン
int val = 0;     // 読み取った値を保持する変数

void setup() {
  pinMode(ledPin, OUTPUT);   // LED用に出力に設定
  pinMode(inPin, INPUT);     // スイッチ用に入力に設定
}

void loop() {
  val = digitalRead(inPin);  // 入力ピンを読む
  if (val==HIGH){
    digitalWrite(ledPin, HIGH); // HIGHなら光る
  }else{
    digitalWrite(ledPin, LOW); // LOWなら消える
  }
}
