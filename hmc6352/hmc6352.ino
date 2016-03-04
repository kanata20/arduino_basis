/* HMC6352で方位を測る      */
#include <Wire.h>　　　　　//I2C通信ライブラリを取り込む

int compassAddress = 0x42 >> 1;         //デジタルコンパスモジュールのアドレス設定
int reading = 0;                        //読み込み値（角度）の変数を用意
 
void setup() {
  Wire.begin();                         //I2C通信開始
  Serial.begin(9600);                  //角度表示のためのシリアル通信開始
  
  /* Continuous Modeに設定する */
  Wire.beginTransmission(compassAddress);       //コマンド送信開始
  Wire.write('G');                              //Gを書き込む(Continuousモード)
  Wire.write(0x74);                                //書き込み先指定
  Wire.write(0x72);                                //モード設定
  Wire.endTransmission();                        //通信終了
  
  delayMicroseconds(70);                         //処理時間待機
} 
  
void loop() {
  Wire.requestFrom(compassAddress, 2);       //センサに２バイト分のデータを要求
  /* 要求したデータが２バイト分来たら */
  if(Wire.available()>1){
    reading = Wire.read();             //１バイト分のデータの読み込み
    reading = reading << 8;            //読み込んだデータを８ビット左シフトしておく
    reading += Wire.read();            //次の１バイト分のデータを読み込み,合成（2バイト）
    reading /= 10;                        //２バイト分のデータを１０で割る(角度に変換)
    Serial.println(reading);           //シリアルで送信
  } 
delay(50);                                //処理のために少し待つ（20Hz）
}

