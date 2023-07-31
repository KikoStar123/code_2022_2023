'''
Author: KIKOSTAR 842544563@outlook.com
Date: 2023-03-26 21:36:30
LastEditors: KIKOSTAR 842544563@outlook.com
LastEditTime: 2023-03-27 19:17:12
FilePath: \CODE\Python\snake.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv(r'D:\program\CODE\Python\DATA3.csv')
dataframeA = ["I1", "I2", "I3"]


class Frame():

    def __init__(self, Index):
        self.Index = Index

    def anylisions(self):
        plt.rcParams['font.family'] = 'SimHei'
        # 输入电压和电流数据

        # U=[365.0,404.7,435.8,546.1,577.0]
        # I=[-1.994,-1.675,-1.421,-0.786,-0.686]
        U = [-1.0, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0,
             26.0, 27.0, 28.0, 29.0, 30.0, 31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0, 40.0, 41.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0, 49.0, 50.0]   # 电压值列表
        I = data[self.Index]
        # 绘制散点图
        plt.scatter(U, I, marker='x')
        plt.xlabel('U/V')
        plt.ylabel('$I/10^{-10}A$', rotation=0, labelpad=10)
        plt.title('光电管的伏安特性曲线'+self.Index)

        # 多项式函数拟合
        fit = np.polyfit(U, I, 3)
        U_new = np.linspace(U[0], U[-1], 300)
        I_fit = np.polyval(fit, U_new)

        # 绘制多项式曲线
        plt.plot(U_new, I_fit, label='伏安特性曲线'+self.Index)
        plt.legend()
        plt.grid(True, linestyle='--', color='grey', which='major')
        plt.minorticks_on()
        plt.grid(True, linestyle=':', color='lightgrey', which='minor')

        plt.show()


A = Frame("I1")
B = Frame("I2")
C = Frame("I3")
A.anylisions()
B.anylisions()
C.anylisions()
