/* シリアル通信                       */
/* センサーの値をシリアル通信で送る   */
int ledPin = 13;        // LEDをデジタルピン13に接続
int analogPin = 3;     // ここにセンサーを接続
int val = 0;             // 読み取った値を格納する変数
int threshold = 512;  // 閾値

void setup() {
  pinMode(ledPin, OUTPUT);   // ピン13を出力に設定
  Serial.begin(9600);         // シリアル通信の初期化
}

void loop() {
  val = analogRead(analogPin);    // アナログピンを読み取る
  Serial.println(val);              // センサー情報を送信

  if (val >= threshold) {
    digitalWrite(ledPin, HIGH);   // LEDをオンに
  } else {
    digitalWrite(ledPin, LOW);    // LEDをオフに
  }
}
