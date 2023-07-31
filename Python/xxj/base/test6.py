import copy
import keyword
import random
players = ['1', '2', '3', '4', '5', '6', '7', '8', '9']

players.insert(2, '10')  # 在第二位插入'10'


a = random.randint(1, 10)

# remove函数是按值删除
# del,pop是删除指定位置的值
a1 = players.sort()  # 排序
b1 = players.reverse()  # 倒叙

for i in range(len(players)):
    print(players[i])  # 列表的遍历

for player in players:
    print(player)  # player为可迭代对象

players = [1, 2, 3, 4, 5, 1, 89]

for i in players:
    if i == 1:
        players.remove(i)  # 反例，一边遍历一边修改列表
print(players)

# 和字符串一样
# 列表可以通过切片来修改内容
# 用来修改列表的数据必须是可迭代对象
players[1:1] = ['2039']  # 在第二个插入

# e.g.

list1 = [1, 2, 3, 8, 4, 5]
list1[3:3] = ['seu']  # 在第三个后面插入可迭代对象6
print(list1)


hunmans = ['珈乐', '奶琳', '嘉然', '向晚', '贝拉']
times = ['开学前', '凌晨', '中午', '晚自习', '下午']
place = ['桃园食堂', "icu", "公园", "枝江学院", "KTV"]
actions = ["唱歌", "跳舞", "上厕所", "吃饭", "睡觉"]

print(f'{random.choice(hunmans)}{random.choice(times)}{random.choice(place)}{random.choice(actions)}')

# b = a.copy()  # 浅复制,不能复制可变对象*****

# 导入copy模块，进行深复制


#列表生成式语法:[表达式 for 变量 in 序列 if 条件]
s = 123
lst1 = [i*i for i in range(1, 11)]
lst2 = [i*i for i in range(1, 11) if i % 2 == 0]
#lst3= [i+j for i in s]

for i in range(1, 10):
    for j in range(1, i+1):
        print(f'{j}*{i}={j*i}', end='\t')
    print()

# 一句话输出乘法表
[print(f'{j}*{i}={j*i}', end='\t' if j < i else '\n')
 for i in range(1, 10) for j in range(1, i+1)]
