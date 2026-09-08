// list 2-1
// Blink on-board LED for 1 Hz
// 2026.09.08 K.Ohashi
#include <Arduino.h>


int LED_PIN = 10; // ボード内 LED ピンの番号をグローバル変数で定義

void setup()    // 最初に１回だけ起動される初期化処理
{ 
    pinMode(LED_PIN, OUTPUT); // LED_PIN を出力に設定
}

void loop()     // 無限に繰り返されるメイン処理
{
    digitalWrite(LED_PIN, HIGH); // LED_PIN に HIGH(5V)を出力、LED 点灯
    delay(100); // 100 ms 待機
    digitalWrite(LED_PIN, LOW); // LED_PIN に LOW(0V)を出力、LED 消灯
    delay(900); // 900 ms 待機
}