// list 2-5
// 外部スイッチ入力
// スイッチが押されるたびにLEDが点灯・消灯を切り替える
// チャタリング不要
// 2026.09.09 K.Ohashi
#include <Arduino.h>


int LED_PIN = 10; // ボード内 LED ピンの番号をグローバル変数で定義
int SW_PIN  = 11; // 外部スイッチのピン番号をグローバル変数で定義

int ledState = LOW; // LEDの状態を保持する変数（初期値は消灯）
int LastButtonState = HIGH;    // スイッチの状態を保持する変数

void setup()
{
    pinMode(LED_PIN, OUTPUT); // LED_PIN を出力に設定
    pinMode(SW_PIN, INPUT); // SW_PIN を入力に設定
}

void loop()
{
    int currentSwState = digitalRead(SW_PIN); // スイッチの状態を読み取る

    // 離されいた状態から押された状態に変化した瞬間(立ち上がり)
    if (LastButtonState == HIGH && currentSwState == LOW)
    {
        ledState = !ledState; // LEDの状態を反転
        digitalWrite(LED_PIN, ledState); // LEDの状態を出力
    }
    LastButtonState = currentSwState; // スイッチの現在の状態を保存
}
