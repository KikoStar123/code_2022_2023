'''
基于数组的编程
Ndim 数组维度
Shape 数组形状
Dtype 元素数据类型 int64等
Size 元素数量
Itemsize 元素内存大小
Flags 内存信息描述
strides 跨度
'''
import numpy as np
# arr2=np.array([1,2,3],[4,5,6])#定义二维数组
# np.array#原生列表或元组 将原生列表或元组等转换为数组
# np.arange#起点/重点步长 可以使用实数
# np.zeros# shape 归零
# np.linspace#等差数列起点/终点/项数
x = np.linspace(10, 20, 5)
print(x)
y = np.linspace(10, 20, 5, endpoint=False)
print(y)  # 等差数列
# 随机函数random
# rand 0和1之间的随机实数 正态分布
# randint 指定范围内的随机整数 均匀分布
# randn  标准正态的随机数 泊松分布
# choice 随机抽取样本 随机打乱顺序
a = np.random.randint(0, 100, (3, 5))
print(a)  # 均匀分布随机数
b = np.random.normal(0, 100, (3, 4))
print(b)
a1 = np.arange(1, 7)
a1.reshape(2, 3)  # 不是就地修改
print(a1)
b1 = a1.reshape(2, 3)  # a和b共享内存 形式不一样可以共享内存 内存当中的数据既可以看成一维的也可以看成二维的
print(b1)
b1[0][0] = 100
print(a1)
print(a1.strides)  # (4,) 步长
print(b1.strides)  # (12,4) b0到b1跳跃12格
a1.resize(2, 3)  # 就地修改
b1 = a1.swapaxes(0, 1)  # 交换0轴和1轴 对步长进行转置
print(b1)
b1 = np.rollaxis(b1, 0, 1)  # 滚动轴

# 切片
print(a[0, 2:4])  # 0行第三个切到第五个
print(a[0::2, 0::2])  # 第0行和第二行的第1个和第3个

# 花式索引
# b = a[[0, 1, 3], 1:]  # 指定0,1,3为列的索引
# 花式索引的结果是新数组

# 布尔索引 提供逻辑表达式，数组回进行广播运算
a2 = np.arange(1, 17).reshape(4, 4)
a3 = a2[a2 > 10]  # 简单的检索
# 操作两个数组时，numpy会逐个比较形状 当其中一个为1时可以运算
b3 = a+1  # 将1广播为a形状的数组转存在b3中
# 形状为1的可以广播为任意维度的数组
x = np.arange(11, 19)
x1, x2, x3 = np.split(x, [3, 5])  # 将一个数组切成三个数组
print(x1, x2, x3)



y = np.arange(11, 49).reshape(6, 8)
y1 = np.vsplit(y, 3)  # 将数据竖着分成三份 横着切
y2 = np.hsplit(y, 4)  # 将数据横着分成四份 竖着切

# concatenate数组沿着某轴拼接
# delete删除第几维度的第几列
# insert增加

# 排序、统计与迭代
np.sort(y1, axis=0)  # 排序第0轴数据的顺序
np.argsort(y2, axis=0)  # 排序后的索引

# 统计函数
print(np.amax(y1, axis=0))  # 最大值
print(np.argmax(y1, axis=0))
print(np.percentile(y1, 50, axis=0))  # 从小到大寻找百分位数50的数
print(np.percentile(y1, 25, axis=0))  # 从小到大寻找百分位数25的数
print(np.mean(y1, axis=0))  # 平均值函数
print(np.average(y1, weights=x1))  # 加权平均数(以x1为权)
print(np.std([1, 2, 3, 4]))  # 标准差
print(np.var([1, 2, 3, 4]))  # 方差
print(np.all(np.isnan(a)))  # 判断脏数据

t = np.where(a > 40)  # 找出a当中的>40的（保留下位置信息）
c = np.extract(np.mod(a, 3) == 0, a)  # 抽取a当中能整除3的所有数据

# 求众数
nums = [1, 2, 3, 6, 5, 6, 6]
a4 = np.bincount(nums)
np.argmax(a4)  # 最大值索引
print(a4)

# 迭代
# np.nditer 迭代器
# 可用for循环迭代

a[...] = a*2  # 每个元素*2
