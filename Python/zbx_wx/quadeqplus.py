'''
Author: error: git config user.name && git config user.email & please set dead value or install git
Date: 2022-10-07 18:52:01
LastEditors: error: git config user.name && git config user.email & please set dead value or install git
LastEditTime: 2022-10-13 14:36:36
FilePath: \CODE\Python\zbx_wx\quadeqplus.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import re
import sys
import math
st1 = str(input("请输入一个二次以下的一元方程"))
st1 = st1.lower()
st1 = st1.replace("^", "")
st1 = st1.replace("**", "")
st1 = st1.replace(" ", "")
b1 = st1.find("+-")
b2 = st1.find("-+")
b3 = st1.find("--")
b4 = st1.find("++")
if b1 != -1 or b2 != -1 or b3 != -1 or b4 != -1:
    print("Error:输入表达式当中存在+-或-+或++或--,程序退出")
    sys.exit()
emark = st1.count("=")
if emark != 1:
    print("Error:输入的表达式缺少=或式子当中有多余一个=，程序退出")
    sys.exit()
st3 = st1.split("=")
l = re.split("([+-])", st3[0])
a = b = c = 0.0
k = len(l)
n = 1
for i in range(0, k):
    vari = l[i].find("x")
    if l[i] == '-':
        n = -1
        continue
    if l[i] == "+":
        n = 1
        continue
    if vari != -1:
        l[i] = l[i].split("x")
        if len(l[i]) > 2:
            print("输入的方程无法识别，未知原因，程序退出")
            sys.exit()
        if (l[i][1] != '0' and l[i][1] != '1' and l[i][1] != '2' and l[i][1] != ''):
            print("Error:输入的表达式阶数高于二次，程序退出")
            sys.exit()
        if l[i][0] == '':
            l[i][0] = '1'
        if l[i][1] == '':
            l[i][1] = '1'
        if l[i][1] == '2':
            a += (n*float(l[i][0]))
        if l[i][1] == '1':
            b += (n*float(l[i][0]))
        if l[i][1] == '0':
            c += (n*float(l[i][0]))
    else:
        c += (n*float(l[i]))
l = re.split("([+-])", st3[1])
k = len(l)
n = -1
for i in range(0, k):
    vari = l[i].find("x")
    if l[i] == '-':
        n = 1
        continue
    if l[i] == "+":
        n = -1
        continue
    if vari != -1:
        l[i] = l[i].split("x")
        if len(l[i]) > 2:
            print("输入的方程无法识别，未知原因，程序退出")
            sys.exit()
        if (l[i][1] != '0' and l[i][1] != '1' and l[i][1] != '2' and l[i][1] != ''):
            print("Error:输入的表达式阶数高于二次，程序退出")
            sys.exit()
        if l[i][0] == '':
            l[i][0] = '1'
        if l[i][1] == '':
            l[i][1] = '1'
        if l[i][1] == '2':
            a += (n*float(l[i][0]))
        if l[i][1] == '1':
            b += (n*float(l[i][0]))
        if l[i][1] == '0':
            c += (n*float(l[i][0]))
    else:
        c += (n*float(l[i]))

if a == 0:
    if b == 0:
        print("x可取任意实数")
        sys.exit(0)
    else:
        print(f'x={-b/c}')
        sys.exit(0)
d = b*b-4*a*c
if d == 0:
    print(f'x={-b/(2*a)}')
if d < 0:
    print("无解")
if d > 0:
    print(f'x1={(-b+math.sqrt(d))/(2.0*a)},x2={(-b-math.sqrt(d))/(2.0*a)}')
