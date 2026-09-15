// list 4-1
// サーボモータの制御
// 角度を指定してサーボモータを動かす
// 2026.09.14 K.Ohashi

#include <Arduino.h>

int SERVO_PIN = 10; // サーボモータの制御ピンの番号をグローバル変数で定義

void setup()
{
    pinMode(SERVO_PIN, OUTPUT);
}

/**
 * @brief 指定した角度で指定した秒数だけサーボを保持する関数
 * @param theta  目標角度 [度] (0 〜 180)
 * @param period 保持時間 [秒]
 * 
 * ### 【計算式の導出（テキスト p.16より）】
 * ```text
 * 1. サーボの仕様：
 *    ・ パルス幅  500 us のとき  0度 (θmin = 0)
 *    ・ パルス幅 2400 us のとき 180度 (θmax = 180)
 * ```
 * 
 * 2. テキスト掲載の公式：
 * ```text
 * θ = θmin + (θmax - θmin) * (A - 500) / (2400 - 500)
 * θ = 0 + (180 - 0) * (A - 500) / 1900
 * θ = 180 * (A - 500) / 1900
 * ```
 * 
 * 3. 求めたい「パルス幅 A [us]」について変形：
 * ```text
 * θ / 180 = (A - 500) / 1900
 * A - 500 = (1900 * θ) / 180
 * A = 500 + (1900 * θ) / 180
 * ```
 * 
 * ### 【パルス周期と繰り返し回数の計算】
 * ```text
 * - サーボ制御の周波数は 50 Hz（周期 T = 20 ms = 20,000 us 固定）
 * - 1秒間に送るパルス数 = 1000 ms / 20 ms = 50 回
 * - 指定秒数 period [s] に必要なループ回数 = period * 50
 * ```
 */
void servo_set(int theta, int period)
{
    // テキストの式: A = 500 + (1900 * theta) / 180 [us]
    long A = 500 + (1900 * (long)theta) / 180; // パルス幅を計算
    long low_time = 20000 - A; // LOW時間を計算（20ms周期）

    int cycles = period * 50; // 20ms周期のため1秒間に50回パルスを送信

    for (int i = 0; i < cycles; i++)
    {
        digitalWrite(SERVO_PIN, HIGH);
        delayMicroseconds(A); // HIGH時間を待機
        digitalWrite(SERVO_PIN, LOW);

        // delayMicrosecondsは最大約16,383usのため2回に分けて待機
        delayMicroseconds(low_time - 10000); // LOW時間を待機
        delayMicroseconds(10000); // LOW時間を待機
    }
}

void loop()
{
    servo_set(0, 2);   // 0度で2秒間保持
    servo_set(90, 1);  // 90度で1秒間保持
    servo_set(180, 2); // 180度で2秒間保持
    servo_set(90, 1);  // 90度で1秒間保持
}