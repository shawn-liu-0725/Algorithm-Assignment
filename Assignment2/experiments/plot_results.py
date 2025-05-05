import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("result.csv")

# 設定字體支援中文
plt.rcParams['font.family'] = 'Microsoft JhengHei'

# 產生圖表：價值比較
plt.figure(figsize=(10, 6))
bar_width = 0.2
index = range(len(df))

plt.bar([i - bar_width for i in index], df["TopDown"], width=bar_width, label="Top-Down DP")
plt.bar(index, df["BottomUp"], width=bar_width, label="Bottom-Up DP")
plt.bar([i + bar_width for i in index], df["Greedy"], width=bar_width, label="Greedy")

plt.xlabel("測資")
plt.ylabel("總價值")
plt.title("各演算法解法比較 - 總價值")
plt.xticks(index, df["測資"])
plt.legend()
plt.tight_layout()
plt.savefig("value_comparison.png")
plt.close()

# 產生圖表：執行時間比較
plt.figure(figsize=(10, 6))
plt.bar(df["測資"], df["執行時間(秒)"], color="skyblue")
plt.xlabel("測資")
plt.ylabel("執行時間（秒）")
plt.title("總執行時間比較")
plt.tight_layout()
plt.savefig("execution_time.png")
plt.close()

print("✅ 圖片已產生：value_comparison.png 與 execution_time.png")
