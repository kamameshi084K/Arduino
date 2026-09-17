## 課題 2-2：SOSモールス信号の点滅

### 1. 回路仕様
* **配線:** Arduino UNO ボード上の内蔵LED（13番ピン）を使用（外付け回路不要）

### 2. 実装コード
```cpp
int LED_PIN = 13; // ボード内 LED ピンの番号をグローバル変数で定義
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

* **待機時間積算:** 各符号（短音・長音）の直後に「音間（1単位）」の消灯を入れているため、文字間（3単位）にするには差分の2単位、単語間（7単位）にするには差分の4単位を追加待機させる必要がある。
* **関数分割:** 共通処理（dot, dash）を部品化して blinkS() や blinkO() を組み立てる構造化プログラミングを意識。