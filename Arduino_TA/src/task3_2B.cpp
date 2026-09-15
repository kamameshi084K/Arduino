// list 3-2
// DCモータの速度制御
// 徐々に速度を変化させる
// 2026.09.14 K.Ohashi
#include <Arduino.h>

int MOTOR_EN  =  9; // モータの有効化ピンの番号をグローバル変数で定義
int MOTOR_IN1 =  8; // モータの入力ピン1の番号をグローバル変数で定義
int MOTOR_IN2 = 11; // モータの入力ピン2の番号をグローバル変数で定義

void setup()
{
    pinMode(MOTOR_EN, OUTPUT);
    pinMode(MOTOR_IN1, OUTPUT);
    pinMode(MOTOR_IN2, OUTPUT);
}

void loop()
{
    // 1. 正転方向に設定
    digitalWrite(MOTOR_IN1, HIGH);
    digitalWrite(MOTOR_IN2, LOW);

    for (int s = 0; s <= 255; s++)
    {
        analogWrite(MOTOR_EN, s);
        delay(15);
    }
    for (int s = 255; s >= 0; s--)
    {
        analogWrite(MOTOR_EN, s);
        delay(15);
    }

    delay(200); // 反転前の休止

    // 2. 逆転方向に設定
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, HIGH);

    for (int s = 0; s <= 255; s++)
    {
        analogWrite(MOTOR_EN, s);
        delay(15);
    }
    for (int s = 255; s >= 0; s--)
    {
        analogWrite(MOTOR_EN, s);
        delay(15);
    }

    delay(200);
}