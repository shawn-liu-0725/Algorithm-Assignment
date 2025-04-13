import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

df = pd.read_csv("c:/Users/user/Algorithm Assignment/Assignment1/code/analyze/experiment_results.csv")

input_types = {
    0: "Random",
    1: "Sorted",
    2: "Reversed",
    3: "Duplicated"
}
df["InputType"] = df["InputType"].map(input_types)

plt.figure(figsize=(14, 8))
sns.lineplot(data=df, x="Size", y="Time(ms)", hue="Algorithm", style="InputType", markers=True)
plt.title("Sorting Time by Algorithm, Size, and Input Type")
plt.ylabel("Execution Time (ms)")
plt.grid(True)
plt.tight_layout()
plt.savefig("performance_chart.png")
plt.show()
