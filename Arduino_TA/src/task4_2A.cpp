// list 4-2
// サーボモータの制御(ライブラリ有り)
// Servoライブラリによる首振り
// 2026.09.14 K.Ohashi

#include <Arduino.h>
#include <Servo.h>

Servo myservo; // サーボモータのオブジェクトを生成
int SERVO_PIN = 10; // サーボモータの制御ピンの番号をグローバル変数で定義

void setup()
{
    myservo.attach(SERVO_PIN); // サーボモータを初期化
}

void loop()
{
    // 0°~>180°までサーボを動かす(2500ms / 180 ステップ　≒ 14msウェイト)
    for (int i = 0; i <= 180; i++)
    {
        myservo.write(i);
        delay(14);
    }

    // 180°~>0°までサーボを動かす(2500ms / 180 ステップ　≒ 14msウェイト)
    for (int i = 180; i >= 0; i--)
    {
        myservo.write(i);
        delay(14);
    }
}