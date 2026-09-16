# アドバンスド・ラーニング2「組込み開発」編 - Arduino TA用リポジトリ

本リポジトリは、千葉工業大学「アドバンスド・ラーニング2」の「組込み開発（Arduino UNO）」編における課題コードおよび回路図・資料を管理するためのものです。
来年にも使えるように作っていくため、必ず後輩に伝えていくこと！

---

## 開発環境
* **マイコンボード:** Arduino UNO R3 (ATmega328P)
* **エディタ・開発基盤:** Visual Studio Code + PlatformIO IDE
* **フレームワーク:** Arduino

---

## ディレクトリ構成とビルド切り替え

PlatformIO環境において、複数の課題コードを単一プロジェクトで管理しています。

```text
Arduino_TA/
├── platformio.ini      # 各課題の環境定義 (build_src_filter)
└── src/
    ├── task2_1A.cpp    # 課題2-1A: ボード内LED点滅
    ├── task2_2A.cpp    # 課題2-2A: SOSモールス信号点滅
    ├── task2_3A.cpp    # 課題2-3A: 外部LEDでのSOS点滅
    ├── task2_4A.cpp    # 課題2-4A: 正論理・負論理LED点滅
    ├── task2_5A.cpp    # 課題2-5A: スイッチによるLEDトグル
    ├── task2_5B.cpp    # 課題2-5B: スイッチによる点滅周波数変更
    ├── task3_1A.cpp    # 課題3-1A: スイッチによるDCモータ正逆転
    ├── task3_2A.cpp    # 課題3-2A: PWMによるDCモータ速度制御
    ├── task3_2B.cpp    # 課題3-2B: DCモータの自動加減速・反転
    ├── task4_1A.cpp    # 課題4-1A: PWM手動生成によるサーボ角度制御関数
    ├── task4_2A.cpp    # 課題4-2A: Servoライブラリによる首振り
    └── task4_2B.cpp    # 課題4-2B: スイッチ連動型サーボ首振り
└── docs/
    ├── task2_3A.pdf     # 課題2-3A: 外部LEDでのSOS点滅 回路図・資料
    ├── task2_4A.pdf     # 課題2-4A: 正論理・負論理LED点滅 回路図・資料
    ├── task2_5A.pdf     # 課題2-5A: スイッチによるLEDトグル 回路図・資料
    ├── task2_5B.pdf     # 課題2-5B: スイッチによる点滅周波数変更 回路図・資料
    ├── task3_1A.pdf     # 課題3-1A: スイッチによるDCモータ正逆転 回路図・資料
    ├── task3_2A.pdf     # 課題3-2A: PWMによるDCモータ速度制御 回路図・資料
    ├── task3_2B.pdf     # 課題3-2B: DCモータの自動加減速・反転 回路図・資料
    ├── task4_1A.pdf     # 課題4-1A: PWM手動生成によるサーボ角度制御関数 回路図・資料
    ├── task4_2A.pdf     # 課題4-2A: Servoライブラリによる首振り 回路図・資料
    └── task4_2B.pdf     # 課題4-2B: スイッチ連動型サーボ首振り 回路図・資料
```