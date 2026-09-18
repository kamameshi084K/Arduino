## 課題 3-1A: 2つのスイッチでモータの回転方向を制御する

### 1. 回路仕様
* **配線:** Arduino UNO ボードの 9番ピンにモータの有効化ピンを接続、8番ピンにモータの入力ピン1を接続、11番ピンにモータの入力ピン2を接続、ここまではArduino UNOボードにMotor Shieldを上からつければよい。2番ピンに正転スイッチを接続、3番ピンに逆転スイッチを接続（プルアップ抵抗を使用）、それらをGNDに接続

![課題3-1A回路図](fig/circuit_3_1A.png)

<div style="break-before: page;"></div>

### 2. 実装コード
```cpp

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
```

### 3. 解説

* **モータの制御:** モータの回転方向は、入力ピン1と入力ピン2のHIGH/LOWの組み合わせで決まる。正転の場合は入力ピン1をHIGH、入力ピン2をLOWに設定し、逆転の場合はその逆に設定する。
* **スイッチの状態:** スイッチは負論理で接続されており、押すとLOW、離すとHIGHとなる。両方のスイッチが押されている場合や両方が離されている場合はモータを停止させる。