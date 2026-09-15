// list 4-2
// サーボモータの制御(ライブラリ有り)
// スイッチ押下時のみ首振り・離したら停止
// 2026.09.14 K.Ohashi

#include <Arduino.h>
#include <Servo.h>

Servo myservo; // サーボモータのオブジェクトを生成
int SERVO_PIN = 10; // サーボモータの制御ピンの番号をグローバル変数で定義
int SW_PIN = 2; // スイッチのピン番号をグローバル変数で定義

int currentPos = 0; // サーボの現在位置を保持する変数
int dir = 1; // サーボの回転方向を保持する変数（1: 正方向, -1: 逆方向）

void setup()
{
    myservo.attach(SERVO_PIN);  // サーボモータを初期化
    myservo.write(currentPos);  // サーボを初期位置に設定
    pinMode(SW_PIN, INPUT);     // スイッチを入力ピンとして設定
}

void loop()
{
    // スイッチが押されてるとき(LOW)のみ首振り動作
    if (digitalRead(SW_PIN) == LOW)
    {
        currentPos += dir; // 現在位置を更新

        // 0°または180°に到達したら方向を反転
        if (currentPos >= 180)
        {
            currentPos = 180; // 上限を180°に制限
            dir = -1; // 方向を逆にする
        }
        else if (currentPos <= 0)
        {
            currentPos = 0; // 下限を0°に制限
            dir = 1; // 方向を正にする
        }
    }

    myservo.write(currentPos); // サーボを現在位置に設定
    delay(14); // サーボの動作速度を制御するためのウェイト
}