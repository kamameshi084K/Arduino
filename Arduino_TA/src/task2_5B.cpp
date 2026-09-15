// list 2-5
// 外部スイッチ入力
// 2つのスイッチを使いLEDの点滅周波数を1~100Hzの範囲で変更する
// 2026.09.09 K.Ohashi
#include <Arduino.h>


int LED_PIN = 10; // ボード内 LED ピンの番号をグローバル変数で定義
int SW1_PIN = 11; // ボード内 LED ピンの番号をグローバル変数で定義
int SW2_PIN = 12; // ボード内 LED ピンの番号をグローバル変数で定義

float freq = 1.0; // 初期周波数 1Hz

void setup()
{
    pinMode(LED_PIN, OUTPUT); // LED_PIN を出力に設定
    pinMode(SW1_PIN, INPUT); // SW1_PIN を入力に設定
    pinMode(SW2_PIN, INPUT); // SW2_PIN を入力に設定
}

void loop()
{
    // SW1が押されている(LOW)なら集荷数増加
    if (digitalRead(SW1_PIN) == LOW)
    {
        // 集荷数を増加させる処理
        freq += 1.0;
        if (freq > 100.0)
        {
            freq = 100.0;
        }
    }
    // SW2が押されている(LOW)なら集荷数減少
    if (digitalRead(SW2_PIN) == LOW)
    {
        // 集荷数を減少させる処理
        freq -= 1.0;
        if (freq < 1.0)
        {
            freq = 1.0;
        }
    }

    // 周波数から周期T[ms]と半周期[ms]を計算
    float T = 1000.0 / freq; // 周期T[ms] = 1000 / freq[Hz]
    int halfT = (int)(T / 2.0); // 半周期[ms] = T / 2

    // デューティ比50%でLEDを点滅させる
    digitalWrite(LED_PIN, HIGH); // LEDを点灯
    delay(halfT); // 半周期待機
    digitalWrite(LED_PIN, LOW); // LEDを消灯
    delay(halfT); // 半周期待機
}
