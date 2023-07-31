import this
x, y = map(float, input('').split())
##一行当中有多个数据的输入格式
##格式化输出如下
a=3
print('%02d'%a)##%02d d代表整数 02代表整数占两位 %代表格式

x=int(input('请输入一个整数：'))
if x%2==0:
    print(x,'是偶数')
else:
    print(x,'是奇数')