import random

a = random.randint(1, 100)
b = int(input("快猜一个1-100的数字凹！"))

while a != b:
    b = int(input("猜的不对凹，能不能再猜一个捏："))
else:
    print("恭喜你猜对啦!")

