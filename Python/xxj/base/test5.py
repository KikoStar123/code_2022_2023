'''
Author: error: git config user.name && git config user.email & please set dead value or install git
Date: 2022-09-29 18:30:32
LastEditors: error: git config user.name && git config user.email & please set dead value or install git
LastEditTime: 2022-09-29 19:24:02
FilePath: \CODE\Python\test5.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE[]
'''
a = [1, 4, 3, 5, 6]

b = sorted(a)  # 排序,并不改变a本身
print(b)
print(a)

a.sort()
print(a)  # 改变a本身的排序

s = 'Hello Mike'
print(s[0:5])  # Hello
print(s[-1:-5:-1])  # ekiM  最后一个:-1为倒叙
print(s[-1:-5])  # 取得空串，越界
# 切片写法
print(s[:])  # 负无穷到正无穷
# 切片不能取到最后一位

b = s[::-1]  # 倒叙赋值

monthnames = 'JANEFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC'
print(monthnames[27:30])  # 内容长度为3

# 切片eg：
dollar = '123.45$'
print(float(dollar[:-1])*7)  # :-1为去掉最右边的那位


# 序列的重复  *号

# len(x)    返回字符串x的长度
# str(x)    将任意类型x转换为字符串类型
# hex(x)     十六精致转换
# e.g.：
print(str(120+5))  # 传入参数值为125


print(dir(str))  # 列出str类的所有方法列表,用help()列出帮助

# find方法：用来查找一个字符串在另一个字符串指定范围中首次出现的位置，如果不存在则返回-1
# index方法 用来查找第一个字符串在另一个字符串指定范围(默认是整个字符串)中首次出现的位置，如果不存在则抛出异常，异常为报错程序终止
# count方法:用来返回一个字符串在另一个字符串中出现的次数，如果不存在则返回0
# eg:
s = 'bird,fish,monkey,rabbit'
print(s.find('fish'))  # 值为5

# split方法
print(s.split(','))  # 按照,切开

# eg2:
time = input().split()
print(':'.join(time))  # 插入:

# lower转小写
# uper转大写
# replace方法，默认全部替换，不修改原来的字符串，返回一个新的字符串
print(s.replace('bird', 'small'))


# strip/lstrip/rstrip删除字符串两端，右端，左端连续空白字符串
# starwith/endwith方法：判断字符串是否以指定字符开始或结束
c = 'P123.py'
key1 = 'py'
print(c.endwith(key1))
print(s[-len(key1):] == key1)

# isupper,islower,isalpha,isdigit方法


# 字符串格式化
# 当要处理包含多个变量和字面量的字符串时，用之前的方法很不方便
# 字符串格式化可以方便地实现这个功能，并且对数据格式进行准确控制
# Python当中有三种字符串格式化的方法：%,format函数和f字符串

# 重要：了解f字符串
name='张三'
height=1.80
print(f'我叫{name:>10},身高{height}米')



