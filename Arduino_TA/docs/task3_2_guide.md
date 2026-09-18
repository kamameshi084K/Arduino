## 課題 3-2A: 2つのスイッチでモータの速度を制御する

### 1. 回路仕様
* **配線:** Arduino UNO ボードの 9番ピンにモータの有効化ピンを接続、8番ピンにモータの入力ピン1を接続、11番ピンにモータの入力ピン2を接続、ここまではArduino UNOボードにMotor Shieldを上からつければよい。2番ピンに増速スイッチを接続、3番ピンに減速スイッチを接続（プルアップ抵抗を使用）、それらをGNDに接続

![課題3-1A回路図](fig/circuit_3_1A.png)

<div style="break-before: page;"></div>

### 2. 実装コード
```cpp

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
```

### 3. 解説

* **速度の変更:** SW1を押すとモータの速度が増加し、SW2を押すとモータの速度が減少するようにしている。速度は0から255までの範囲で制御される。
* **PWM制御:** `analogWrite`関数を使用して、モータの有効化ピンにPWM信号を出力し、速度を制御している。



## 課題 3-2B: 2つのスイッチでモータの速度を制御する

### 1. 回路仕様
* **配線:** Arduino UNO ボードの 9番ピンにモータの有効化ピンを接続、8番ピンにモータの入力ピン1を接続、11番ピンにモータの入力ピン2を接続、ここまではArduino UNOボードにMotor Shieldを上からつければよい。

![課題3-2B回路図](fig/circuit_3_2B.png)

<div style="break-before: page;"></div>

### 2. 実装コード
```cpp

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
```

### 3. 解説

* **速度の変化:** モータの速度を徐々に増加させ、最大値に達したら徐々に減少させることで、モータの回転速度を滑らかに制御している。
* **正転・逆転の切り替え:** モータの入力ピンの状態を切り替えることで、正転と逆転を制御している。
* **デッドバンド:** デューティ比が小さい領域では静止摩擦にトルクが負けるため、モータが回転を始めない現象は正常な物理特性。