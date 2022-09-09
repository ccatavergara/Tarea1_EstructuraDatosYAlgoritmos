# -*- coding: utf-8 -*-
"""
Created on Tue Sep  6 19:19:43 2022

@author: samue
"""

import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

df = pd.read_excel('../tables/resultados-sort-style-litvalue.xlsx')


x_size = df["Tamaño (n)"].values.tolist()

y_time_quick_sort = df["Quick Sort (ms)"].values.tolist()
y_time_merge_sort = df["Merge Sort (ms)"].values.tolist()

plt.ticklabel_format(style='plain')
plt.ylabel("Tiempo (ms)")
plt.xlabel("Tamaño (n)")
plt.yticks(np.arange(0, 50, 10))
plt.xticks(np.arange(10000, 100001, 20000))
plt.plot(x_size, y_time_quick_sort, label='Quick  Sort')
plt.plot(x_size, y_time_merge_sort, label='Merge Sort')
plt.legend()

plt.show()