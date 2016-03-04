/* キャリブレーション */

#include <Wire.h>       //I2C通信ライブラリを取り込む

int compassAddress = 0x42 >> 1;       //デジタルコンパスモジュールのアドレス設定

void setup() {
  Serial.begin(9600);                //シリアル通信開始
  /* キャリブレーション開始コマンド送信 */
  Wire.beginTransmission(compassAddress);     //コマンド送信開始
  Wire.write('C');                             //’C’を書き込む(キャリブレーションモード)
  Wire.endTransmission();                    //データ送信して送信終了
  Serial.print("Start Calibration \n");        //シリアルで表示

  Serial.print("Rotate the Sensor! \n");       //シリアルで表示
  delay(30000);                                    // 30秒ほど待つ（6秒〜3分まで）
/************************************************/
/* この30秒間に数回モジュールを回転させると，方位が修正される */
/************************************************/

  /* キャリブレーション終了コマンド送信 */
  Wire.beginTransmission(compassAddress) ;     //コマンド送信開始
  Wire.write('E');                           //’E’を書き込む(キャリブレーションモード終了)
  Wire.endTransmission();                 //データ送信して送信終了
  Serial.print("Calibration Finished! \n");    //シリアルで表示
} 
  
void loop() { //何もしない 
}
