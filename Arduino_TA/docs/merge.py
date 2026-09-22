import glob

# 結合したいファイル順に並べる
files = [
    "task2_1_guide.md",
    "task2_2_guide.md",
    "task2_3_guide.md",
    "task2_4_guide.md",
    "task2_5_guide.md",
    "task3_1_guide.md",
    "task3_2_guide.md",
    "task4_1_guide.md",
    "task4_2_guide.md",
]

PAGE_BREAK = '\n\n<div style="break-before: page;"></div>\n\n'
merged_content = []

for filename in files:
    try:
        with open(filename, "r", encoding="utf-8") as f:
            merged_content.append(f.read().strip())
    except FileNotFoundError:
        print(f"Warning: {filename} が見つかりません。スキップします。")

# 各ファイルの内容を改ページタグで繋げて出力
output_filename = "complete_guide.md"
with open(output_filename, "w", encoding="utf-8") as f:
    f.write(PAGE_BREAK.join(merged_content))

print(f"結合完了: {output_filename}")