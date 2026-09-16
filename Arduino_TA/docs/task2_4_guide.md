## 課題 2-4: 2つのLEDを交互に点滅させる

### 1. 回路仕様
* **配線:** Arduino UNO ボードの 10番、9番ピンに外付けLEDを接続（抵抗は 220Ω を使用）

![課題2-5A回路図](fig/circuit_2_4A.png)

### 2. 実装コード
```cpp

int LED_PIN = 10; // ボード内 LED ピンの番号をグローバル変数で定義
int LED_PIN2 = 9; // ボード内 LED ピンの番号をグローバル変数で定義

int Time1 = 200;        // 点灯・消灯の基本単位時間をグローバル変数で定義（ms）
int Time2 = 100;        // 点灯・消灯の基本単位時間をグローバル変数で定義（ms）
int TimeOff = 200;      // 点灯・消灯の基本単位時間をグローバル変数で定義（ms）
int TimeInterval = 500; // 点灯・消灯の基本単位時間をグローバル変数で定義（ms）
int ReeatCount = 3;     // 何回繰り返すかをグローバル変数で定義

void setup()    // 最初に１回だけ起動される初期化処理
{ 
    pinMode(LED_PIN, OUTPUT); // LED_PIN を出力に設定
    pinMode(LED_PIN2, OUTPUT); // LED_PIN2 を出力に設定

    // 初期状態を設定(両方のLEDを消灯)
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, HIGH); // led2は負論理なのでHIGHで消灯
}

void loop() // 無限に繰り返されるメイン処理
{
    for (int i = 0; i < ReeatCount; i++)
    {
        // led1を点灯、led2を消灯
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(LED_PIN2, HIGH); // led2は負論理なのでHIGHで消灯
        delay(Time1);

        // led1を消灯、led2を点灯
        digitalWrite(LED_PIN, LOW);
        digitalWrite(LED_PIN2, LOW); // led2は負論理なのでLOWで点灯
        delay(Time2);

        // 両方のLEDを消灯
        digitalWrite(LED_PIN, LOW);
        digitalWrite(LED_PIN2, HIGH); // led2は負論理なのでHIGHで消灯
        delay(TimeOff);
    }

    // 3回繰り返した後、次の点滅までの間隔を空ける
    delay(TimeInterval);
}
```

### 3. 解説

* **負論理:** LED2のアノードは常時5Vに接続されているため、D9ピンがLOW（0V）になった瞬間のみ電位差（5V - 0V = 5V）が生じて点灯する。