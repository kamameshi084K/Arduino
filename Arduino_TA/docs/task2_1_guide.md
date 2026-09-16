## 課題 2-1A：ボード内LEDの点滅周期変更

### 1. 回路仕様
* **配線:** Arduino UNO ボード上の内蔵LED（13番ピン）を使用（外付け回路不要）

### 2. 実装コード
```cpp
int LED_PIN = 13; // ボード内 LED ピンの番号をグローバル変数で定義

void setup()    // 最初に１回だけ起動される初期化処理
{ 
    pinMode(LED_PIN, OUTPUT); // LED_PIN を出力に設定
}

void loop()     // 無限に繰り返されるメイン処理
{
    digitalWrite(LED_PIN, HIGH); // LED_PIN に HIGH(5V)を出力、LED 点灯
    delay(100); // 100 ms 待機
    digitalWrite(LED_PIN, LOW); // LED_PIN に LOW(0V)を出力、LED 消灯
    delay(900); // 900 ms 待機
}
```

### 3. 解説
* **周期と周波数の関係:** 周期*T*=100 *ms* + 900 *ms* = 1000 *ms* = 1 *s* であり、点滅周波数は*f* = 1/T = 1/1 *s* = 1 *Hz*
* **delay()関数:** 指定した時間(ms)だけ処理を停止する関数。ここでは、LEDの点灯・消灯の間隔を制御するために使用。