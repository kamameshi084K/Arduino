## 課題 4-2A: 2つのスイッチでモータの速度を制御する

### 1. 回路仕様
* **配線:** Arduino UNO ボードの 9番ピンにモータの有効化ピンを接続、8番ピンにモータの入力ピン1を接続、11番ピンにモータの入力ピン2を接続、ここまではArduino UNOボードにMotor Shieldを上からつければよい。2番ピンに増速スイッチを接続、3番ピンに減速スイッチを接続（プルアップ抵抗を使用）、それらをGNDに接続

![課題3-1A回路図](fig/circuit_4_1A.png)

<div style="break-before: page;"></div>

### 2. 実装コード
```cpp

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
```

### 3. 解説
* **サーボモータの制御:** ArduinoのServoライブラリを使用することで、PWM信号の生成やパルス幅の計算を自動で行うことができる。`myservo.write(angle)` メソッドを使用して、指定した角度にサーボモータを回転させることができる。
<div style="break-before: page;"></div>

