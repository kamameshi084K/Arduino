// list 3-2
// DCモータの速度制御
// 2つのスイッチを使いモータの回転速度を変更する
// 2026.09.09 K.Ohashi
#include <Arduino.h>

int MOTOR_EN  =  9; // モータの有効化ピンの番号をグローバル変数で定義
int MOTOR_IN1 =  8; // モータの入力ピン1の番号をグローバル変数で定義
int MOTOR_IN2 = 11; // モータの入力ピン2の番号をグローバル変数で定義

int SW1_PIN = 2; // 増速
int SW2_PIN = 3; // 減速

int speedVal = 0; // モータの速度を保持する変数（初期値は停止）

void setup()
{
    pinMode(MOTOR_EN, OUTPUT);
    pinMode(MOTOR_IN1, OUTPUT);
    pinMode(MOTOR_IN2, OUTPUT);

    pinMode(SW1_PIN, INPUT);
    pinMode(SW2_PIN, INPUT);

    // 正転方向に固定
    digitalWrite(MOTOR_IN1, HIGH);
    digitalWrite(MOTOR_IN2, LOW);
}

void loop()
{
    // SW1が押されている(LOW)なら速度増加
    if (digitalRead(SW1_PIN) == LOW)
    {
        speedVal += 1; // 速度を増加
        if (speedVal > 255)
        {
            speedVal = 255; // 最大値に制限
        }
    }
    // SW2が押されている(LOW)なら速度減少
    if (digitalRead(SW2_PIN) == LOW)
    {
        speedVal -= 1; // 速度を減少
        if (speedVal < 0)
        {
            speedVal = 0; // 最小値に制限
        }
    }

    analogWrite(MOTOR_EN, speedVal); // モータの速度を設定
    delay(30); // 速度変更の反映を待つ
}