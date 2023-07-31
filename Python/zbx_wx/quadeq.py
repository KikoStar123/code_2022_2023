import math
a = float(input("a="))
b = float(input("b="))
c = float(input("c="))
d = b*b-4*a*c

if a != 0:
    if d < 0:
        print("无解")
    if d == 0:
        print(f'x12={(0-b+math.sqrt(d))/(2*a)}')
    if d > 0:
        print(f'x1={(0-b+math.sqrt(d))/(2*a)},x2={(0-b-math.sqrt(d))/(2*a)}')
else:
    print("输入的方程不是二元方程")
