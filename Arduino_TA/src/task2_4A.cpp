// list 2-4
// Blink extrenal two leds (日本語: 外付けLED2個を点滅させる)
// led1 is positive-logic, led2 is negative logic(日本語: led1は正論理、led2は負論理)
// 2026.09.09 K.Ohashi
#include <Arduino.h>


int LED_PIN = 10; // ボード内 LED ピンの番号をグローバル変数で定義
int LED_PIN2 = 9; // ボード内 LED ピンの番号をグローバル変数で定義
int Time1 = 200; // 点灯・消灯の基本単位時間をグローバル変数で定義（ms）
int Time2 = 100; // 点灯・消灯の基本単位時間をグローバル変数で定義（ms）
int TimeOff = 200; // 点灯・消灯の基本単位時間をグローバル変数で定義（ms）
int TimeInterval = 500; // 点灯・消灯の基本単位時間をグローバル変数で定義（ms）
int ReeatCount = 3; // 何回繰り返すかをグローバル変数で定義

void setup()    // 最初に１回だけ起動される初期化処理
{ 
    pinMode(LED_PIN, OUTPUT); // LED_PIN を出力に設定
    pinMode(LED_PIN2, OUTPUT); // LED_PIN2 を出力に設定

    // 初期状態を設定(両方のLEDを消灯)
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, HIGH); // led2は負論理なのでHIGHで消灯
}

void loop()     // 無限に繰り返されるメイン処理
{
    for (int i = 0; i < ReeatCount; i++)
    {
        // led1を点灯、led2を消灯
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(LED_PIN2, HIGH); // led2は負論理なのでHIGHで消灯
        delay(Time1);

        // led1を消灯、led2を点灯
        digitalWrite(LED_PIN, LOW);
        digitalWrite(LED_PIN2, LOW); // led2は負論理なのでLOWで点灯
        delay(Time2);

        // 両方のLEDを消灯
        digitalWrite(LED_PIN, LOW);
        digitalWrite(LED_PIN2, HIGH); // led2は負論理なのでHIGHで消灯
        delay(TimeOff);
    }

    // 3回繰り返した後、次の点滅までの間隔を空ける
    delay(TimeInterval);
}