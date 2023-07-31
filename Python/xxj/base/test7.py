# 字典
# 基本数据结构-映射
# 在内存中存放键值对，键值一一对应
# 键是唯一的
# 键必须是不可变类型 一般是字符串、数字、或者元组 而值却可以是任何数据类型
# 字典不是序列 因此不支持索引 切片 重复 等运算

# 字典是可修改的数据类型


country_areas = {}  # 空字典
country_areas1 = {'俄罗斯': 1708, '加拿大': 997, '中国': 1293}
country_areas2 = {'俄罗斯': 1708, '加拿大': 997}
country_areas1 = country_areas2.update()  # 会修改字典本身


#counry = {**country_areas1, **country_areas2}
# **操作符进行字典解包
# 将一个字典拆分成若干个键值对

a = country_areas1.get('中国')
print(a)


def triangle_area(a, b, c):
    if type(a) not in (float, int):
        raise TypeError("a not a num")
    if type(b) not in (float, int):
        raise TypeError("a not b num")
    if type(c) not in (float, int):
        raise TypeError("a not c num")
    if a+b < c or a+c < b or c+b < a:
        raise ValueError("应大于第三边")
    return 1


try:
    print(triangle_area('a', 4, 5))
except TypeError as t:
    print(t)
except ValueError as t:
    print(t)