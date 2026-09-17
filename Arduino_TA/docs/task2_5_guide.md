## 課題 2-5A: スイッチを押すとLEDが点灯し、もう一度押すと消灯する

### 1. 回路仕様
* **配線:** Arduino UNO ボードの 10番ピンに外付けLEDを接続（抵抗は 220Ω を使用）、11番ピンに外付けスイッチを接続（プルアップ抵抗を使用）、それらをGNDに接続

![課題2-5A回路図](fig/circuit_2_5A.png)

<div style="break-before: page;"></div>

### 2. 実装コード
```cpp

int LED_PIN = 10; // ボード内 LED ピンの番号をグローバル変数で定義
int SW_PIN  = 11; // 外部スイッチのピン番号をグローバル変数で定義

int ledState = LOW; // LEDの状態を保持する変数（初期値は消灯）
int LastButtonState = HIGH;    // スイッチの状態を保持する変数

void setup()
{
    pinMode(LED_PIN, OUTPUT); // LED_PIN を出力に設定
    pinMode(SW_PIN, INPUT); // SW_PIN を入力に設定
}

void loop()
{
    int currentSwState = digitalRead(SW_PIN); // スイッチの状態を読み取る

    // 離されいた状態から押された状態に変化した瞬間(立ち上がり)
    if (LastButtonState == HIGH && currentSwState == LOW)
    {
        ledState = !ledState; // LEDの状態を反転
        digitalWrite(LED_PIN, ledState); // LEDの状態を出力
    }
    LastButtonState = currentSwState; // スイッチの現在の状態を保存
}
```

### 3. 解説

* **エッジ検出:** スイッチが「LOWであるか」ではなく「HIGHからLOWに変わった瞬間」を捉えないと、長押し時に高速点滅してしまうこと注意。
* **プルアップ抵抗:** スイッチが押されていない状態では、入力ピンはHIGHに保たれるようにするため、プルアップ抵抗を使用する。
* **LEDの状態保持:** `ledState` 変数を使用して、LEDの現在の状態（点灯/消灯）を保持し、スイッチが押されるたびに反転させることで、トグル動作にしてる。

<div style="break-before: page;"></div>

## 課題 2-5B: 2つのスイッチを押すとLEDの点滅周波数が変化する

### 1. 回路仕様
* **配線:** Arduino UNO ボードの 10番ピンに外付けLEDを接続（抵抗は 220Ω を使用）、11番ピンに外付けスイッチ1を接続、12番ピンに外付けスイッチ2を接続（プルアップ抵抗を使用）、それらをGNDに接続

![課題2-5B回路図](fig/circuit_2_5B.png)

<div style="break-before: page;"></div>

### 2. 実装コード
```cpp

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
```

### 3. 解説

* **周波数の変更:** SW1を押すと周波数が増加し、SW2を押すと周波数が減少するようにしている。周波数は1Hzから100Hzまでの範囲で制御される。
* **周期と半周期の計算:** 周波数から周期Tを計算し、半周期を求めることで、LEDの点滅をデューティ比50%で制御している。
