'''
Author: KIKOSTAR 842544563@outlook.com
Date: 2023-03-26 23:41:25
LastEditors: KIKOSTAR 842544563@outlook.com
LastEditTime: 2023-03-27 18:31:14
FilePath: \CODE\Python\snak2e.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import numpy as np
import matplotlib.pyplot as plt
# 生成数据
x = [365.0, 404.7, 435.8, 546.1, 577.0]
y = [-1.994, -1.675, -1.321, -0.786, -0.686]


# 绘制散点图
plt.scatter(x, y)

plt.title('Scatter Plot')
plt.xlabel('X')
plt.ylabel('Y')

plt.show()

# 计算斜率和截距
slope, intercept = np.polyfit(x, y, 1)

print('Slope:', slope)
print('Intercept:', intercept)



# 绘制散点图
plt.scatter(x, y)

# 绘制回归线
y = slope*x + intercept
plt.plot(x, y, color='r')

plt.title('Linear Regression')
plt.xlabel('X')
plt.ylabel('Y')

plt.show()

