'''
Author: KIKOSTAR 842544563@outlook.com
Date: 2023-03-26 21:36:30
LastEditors: KIKOSTAR 842544563@outlook.com
LastEditTime: 2023-05-18 09:57:17
FilePath: \CODE\Python\snake.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv(r'D:\program\CODE\Python\DATA4.csv')
dataframeA = ["I1"]


class Frame():

    def __init__(self, Index):
        self.Index = Index

    def anylisions(self):
        plt.rcParams['font.family'] = 'SimHei'
        # 输入电压和电流数据

        # U=[365.0,404.7,435.8,546.1,577.0]
        # I=[-1.994,-1.675,-1.421,-0.786,-0.686]
        U = [440, 450, 460, 470, 480, 490, 500, 510, 520, 530, 540]   # 横轴列表
        I = data[self.Index]
        # 绘制散点图
        plt.scatter(U, I, marker='x')
        plt.xlabel('$λ/nm$')
        plt.ylabel('吸光度/A', rotation=0, labelpad=10)
        plt.title('波长-吸光度曲线')

        # 多项式函数拟合
        fit = np.polyfit(U, I, 3)
        U_new = np.linspace(U[0], U[-1], 300)
        I_fit = np.polyval(fit, U_new)

        # 绘制多项式曲线
        plt.plot(U_new, I_fit, label='波长-吸光度曲线')
        plt.legend()
        plt.grid(True, linestyle='--', color='grey', which='major')
        plt.minorticks_on()
        plt.grid(True, linestyle=':', color='lightgrey', which='minor')

        plt.show()


A = Frame("I1")

A.anylisions()
