// list 3-1
// DCモータの駆動
// 2つのスイッチを使いモータの回転方向を切り替え、同時押しは停止
// 2026.09.09 K.Ohashi
#include <Arduino.h>

int MOTOR_EN  =  9; // モータの有効化ピンの番号をグローバル変数で定義
int MOTOR_IN1 =  8; // モータの入力ピン1の番号をグローバル変数で定義
int MOTOR_IN2 = 11; // モータの入力ピン2の番号をグローバル変数で定義

int SW1_PIN = 2; // 正転スイッチ
int SW2_PIN = 3; // 逆転スイッチ

void setup()
{
    pinMode(MOTOR_EN, OUTPUT); // MOTOR_EN を出力に設定
    pinMode(MOTOR_IN1, OUTPUT); // MOTOR_IN1 を出力に設定
    pinMode(MOTOR_IN2, OUTPUT); // MOTOR_IN2 を出力に設定

    pinMode(SW1_PIN, INPUT); // SW1_PIN を入力に設定
    pinMode(SW2_PIN, INPUT); // SW2_PIN を入力に設定
}

/**
 * @brief モータを正転させる関数
 * 
 */
void MotorCW()
{
    digitalWrite(MOTOR_EN, HIGH);   // モータを有効化
    digitalWrite(MOTOR_IN1, HIGH); // モータの入力ピン1をHIGHに設定
    digitalWrite(MOTOR_IN2, LOW);  // モータの入力ピン2をLOWに設定
}

/**
 * @brief モータを逆転させる関数
 * 
 */
void MotorCCW()
{
    digitalWrite(MOTOR_EN, HIGH);   // モータを有効化
    digitalWrite(MOTOR_IN1, LOW);  // モータの入力ピン1をLOWに設定
    digitalWrite(MOTOR_IN2, HIGH); // モータの入力ピン2をHIGHに設定
}

/**
 * @brief モータを停止させる関数
 * 
 */
void MotorStop()
{
    digitalWrite(MOTOR_EN, LOW);   // モータを無効化
}

void loop()
{
    int sw1 = digitalRead(SW1_PIN); // SW1の状態を読み取る
    int sw2 = digitalRead(SW2_PIN); // SW2の状態を読み取る

    // 負論理：押すとLOW
    // 両方押し（LOW, LOW）または　両方離し（HIGH, HIGH）の場合は停止
    if ((sw1 == LOW && sw2 == LOW) || (sw1 == HIGH && sw2 == HIGH))
    {
        MotorStop();
    }
    else if (sw1 == LOW) // SW1が押されている場合は正転
    {
        MotorCW();
    }
    else if (sw2 == LOW) // SW2が押されている場合は逆転
    {
        MotorCCW();
    }
}