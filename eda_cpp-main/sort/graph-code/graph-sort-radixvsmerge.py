import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

df = pd.read_excel('../tables/resultados-sort-radixvsmerge.xlsx')


x_size_1m = df["Tamaño (n)"].values.tolist()
y_time_quick_sort = df["Quick Sort (ms)"].values.tolist()
y_time_radix_sort = df["Radix Sort (ms)"].values.tolist()

plt.ticklabel_format(style='plain')
plt.ylabel("Tiempo (ms)")
plt.xlabel("Tamaño (n)")
plt.yticks(np.arange(0, 201, 25))
plt.xticks(np.arange(100000, 1000001, 200000))
plt.plot(x_size_1m, y_time_radix_sort, label='Radix Sort')
plt.plot(x_size_1m, y_time_quick_sort, label='Merge Sort')
plt.legend()

plt.show()