## 課題 2-3：マイコン外のLEDによるSOSモールス信号の点滅

### 1. 回路仕様
* **配線:** Arduino UNO ボードの 10番ピンに外付けLEDを接続（抵抗は 220Ω を使用）

![課題2-5A回路図](fig/circuit_2_3A.png)

### 2. 実装コード
```cpp
int LED_PIN = 10; // ボード外 LED ピンの番号をグローバル変数で定義
int UNIT_TIME = 100; // 点灯・消灯の基本単位時間をグローバル変数で定義（ms）

void setup()    // 最初に１回だけ起動される初期化処理
{ 
    pinMode(LED_PIN, OUTPUT); // LED_PIN を出力に設定
}

/**
 * @brief 点灯時間を表す関数
 * @details 点灯時間は1単位で、消灯時間は1単位の間隔を空ける
 */
void dot()
{
    digitalWrite(LED_PIN, HIGH);
    delay(UNIT_TIME);
    digitalWrite(LED_PIN, LOW);
    delay(UNIT_TIME); // 音間 (1単位)
}

/**
 * @brief 長点時間を表す関数
 * @details 点灯時間は3単位で、消灯時間は1単位の間隔を空ける
 */
void dash()
{
    digitalWrite(LED_PIN, HIGH);
    delay(UNIT_TIME * 3);
    digitalWrite(LED_PIN, LOW);
    delay(UNIT_TIME); // 音間 (1単位)
}

/**
 * @brief S点灯を表す関数
 * @details 最後の点灯後は、3単位の間隔を空けるので、点灯後に2単位の間隔を空ける
 */
void blinkS()
{
    dot();
    dot();
    dot();
    delay(UNIT_TIME * 2);
}

/**
 * @brief O点灯を表す関数
 * @details 最後の点灯後は、3単位の間隔を空けるので、点灯後に2単位の間隔を空ける
 */
void blinkO()
{
    dash();
    dash();
    dash();
    delay(UNIT_TIME * 2);
}

void loop()     // 無限に繰り返されるメイン処理
{
    blinkS();
    blinkO();
    blinkS();

    // Sの終了時に文字間(3単位)待機済みなので、単語間(7単位)待機するために、4単位の間隔を空ける
    delay(UNIT_TIME * 4);
}
```

### 3. 解説

* **LEDの極性:** の長さ（長＝アノード、短＝カソード）を確認。
* **抵抗:** 220Ω 抵抗を挟まないと過電流でLEDおよびArduinoの出力ポートが破損する危険がある。