import os
import subprocess
import time

INPUT_DIR = "inputs"
EXECUTABLE = "../build/knapsack_solver.exe"
CSV_OUTPUT = "result.csv"
MD_OUTPUT = "summary.md"

def parse_output(output):
    results = {}
    for line in output.strip().split('\n'):
        if "Top-Down" in line:
            results["topdown"] = int(line.split(":")[1].strip())
        elif "Bottom-Up" in line:
            results["bottomup"] = int(line.split(":")[1].strip())
        elif "Greedy" in line:
            results["greedy"] = int(line.split(":")[1].strip())
    return results

results_list = []
markdown_lines = ["# 實驗結果總結\n"]

for filename in os.listdir(INPUT_DIR):
    if not filename.endswith(".txt"):
        continue

    input_path = os.path.join(INPUT_DIR, filename)
    print(f"正在執行：{filename} ...")

    start = time.time()
    try:
        result = subprocess.run(
            [EXECUTABLE, input_path],
            capture_output=True,
            text=True,
            encoding='utf-8',
            timeout=10  # 避免無限等待
        )
        end = time.time()
    except subprocess.TimeoutExpired:
        print(f"執行 {filename} 超時")
        continue

    elapsed = round(end - start, 6)
    output = result.stdout
    parsed = parse_output(output)

    # 儲存至 list 中以便輸出 CSV
    results_list.append({
        "filename": filename,
        "topdown": parsed.get("topdown", "N/A"),
        "bottomup": parsed.get("bottomup", "N/A"),
        "greedy": parsed.get("greedy", "N/A"),
        "time": elapsed
    })

    # 產生 Markdown 匯出
    markdown_lines.append(f"## {filename}")
    markdown_lines.append(f"- 執行時間：{elapsed} 秒")
    markdown_lines.append("```")
    markdown_lines.append(output.strip())
    markdown_lines.append("```\n")

# 輸出 CSV
with open(CSV_OUTPUT, "w", encoding="utf-8") as f:
    f.write("測資,TopDown,BottomUp,Greedy,執行時間(秒)\n")
    for r in results_list:
        f.write(f"{r['filename']},{r['topdown']},{r['bottomup']},{r['greedy']},{r['time']}\n")

# 輸出 Markdown
with open(MD_OUTPUT, "w", encoding="utf-8") as f:
    f.write("\n".join(markdown_lines))

print("\n✅ 實驗完成，結果已輸出至 result.csv 與 summary.md。")
