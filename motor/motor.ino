/* モーター回す */

int analogPin1 =  5; // ピンをわかりやすい変数で書く
int analogPin2 =  6; // ピンをわかりやすい変数で書く

int power = 128;    // pwmデューティ比

void setup(){
  /* ピンのモード設定 */
  pinMode(analogPin1, OUTPUT);
  pinMode(analogPin2, OUTPUT);
}

void loop(){
  analogWrite(analogPin1, 0);     //ピン1はL
  analogWrite(analogPin2, power); //ピン2はH
  delay(1000);
  analogWrite(analogPin1, power); //ピン1はH
  analogWrite(analogPin2, 0);     //ピン2はL
  delay(1000);
}
