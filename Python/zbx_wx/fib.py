'''
Author: error: git config user.name && git config user.email & please set dead value or install git
Date: 2022-10-18 12:47:11
LastEditors: error: git config user.name && git config user.email & please set dead value or install git
LastEditTime: 2022-10-18 19:15:31
FilePath: \CODE\Python\zbx_wx\fib.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
#


flag = True
a = [0]*100

def fib1(n):
    if n == 1 or n == 2:
        return 1
    else:
        return (fib1(n-1)+fib1(n-2))


def fib2(n):
    global a
    global flag
    a[0] = 1
    a[1] = 1
    if flag:
        for i in range(2, 100):
            a[i] = a[i-1]+a[i-2]
        flag = False
    return a[n-1]


n = int(input('Please enter a number '))
print(fib2(n))
print(fib2(n+2))
print(fib1(n))
