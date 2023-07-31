x, y, z = map(int, input('������������').split())  # �������
if x >= y and x >= z:
    print(x)
elif y >= x and y >= z:
    print(y)
else:
    print(z)

month = 4
if month in (1, 2, 5, 7, 8, 10, 12):
    print(31)
# ��֧�ṹ

match month:
    case 1:
        days = 2
        # ������cpp��case�ṹ

i, total = 1, 0
while i <= 100:
    total += i
    i += 1
print(total)  # 5050

for ch in 'nanjing':
    print(ch)
# 迭代nanjing
