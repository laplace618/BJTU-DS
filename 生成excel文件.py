import pandas as pd

# 从文本文件读取数据
data = pd.read_csv("data.txt", delimiter=" ", names=["x", "y1", "y2", "y3", "y4", "y5"])

# 将数据保存为Excel文件
data.to_excel("data.xlsx", index=False)
