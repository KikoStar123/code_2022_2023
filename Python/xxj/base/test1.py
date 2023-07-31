'''
Author: error: git config user.name && git config user.email & please set dead value or install git
Date: 2022-09-15 19:27:04
LastEditors: error: git config user.name && git config user.email & please set dead value or install git
LastEditTime: 2022-09-22 16:20:02
FilePath: \CODE\python\test1.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import math  # 导入数学模块
import keyword
msg = "Hello world!"
print(msg)
print("你好")
print(math.factorial(100))##x的阶乘
print(0.1+0.2 == 0.3)
a = 'seu'
print(id(a))
b = a

# python当中的部分模块
# python官网当中可以查手册
print(id(b))
print(round(3.1415926535897932384626433, 2))  # 四舍五入函数
print(divmod(7, 2))  # 返回商和余数
print(abs(-2))  # 返回绝对值
print(pow(2, 3))  # 幂运算
print(max(3, 1, 2, 3, 4, 5, 6,))  # 最大值
print(min(3, 1, 2, 3, 4, 6, 7, 8, 9))  # 最小值
print(sum((3, 1, 2)))  # 总和，注意参数格式，必须要双括号
print(dir(math))  # 列出模块所有的功能和数据
print(math.sin(math.pi/2))  # 正弦
print(math.ceil(3.6))  # 向上取整

month = 2
print(1 < month < 3)  # 关系运算符可以连续使用
print('3' > '12')  # 只比较第一个字符
print('ABC' > 'abc')  # 只比较第一个字符
print('男' > '女')  # 只比较第一个字符
print(ord('男'))  # 获取一个字符或者字符串的unicode编码值
print(chr(12078))  # 输出一个unicode编码为12078的符号

for i in range(0, 10):
    print(i)  # 循环体表示
    # print自动换行

s = 'Nanjing'
print('nan' in s)  # 判断是否在容器当中
a = [1, 2, 3, 4]
print(5 not in a)

a = b = 2
print(a is b)
a = 3
print(a is not b)  # 判断是不是同一个东西

r = float(input('请输入圆的半径'))
area = 3.14*r**2
print(area)

eval('1+1')  # 将一切看起来像表达式的字符串计算出来
