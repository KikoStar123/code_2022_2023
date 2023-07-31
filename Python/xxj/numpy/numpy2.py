import numpy as np
a = np.char.center('Hello', 3)  # 字符串处理
# 字符串处理有许多的方法，查阅手册

# 视图
a = np.arrnge(6).reshape(2, 3)
b = np.arrnge(6).reshape(3, 2)
b = a  # 引用
b = np.resize(3, 2)  # a,b完全一体
print(a.shape)

b = np.view(3, 2)  # 视图，映射a当中的数据

#文件读取与储存
np.save('outfile', a)  # 默认使用python序列化生成一个npy文件
c = np.load('outfile.npy')  # 文件载入
print(b)
np.savetxt("outfile.txt", b)
d=np.loadtxt("outfile.txt")
#numpy的应用