import math
import re
import sys
import PySimpleGUI as sg


def hidden_errors(errors):
    layout = [[sg.Text('Got an error:')],
              [sg.Text(errors)],
              [sg.Button('Exit', key="-EXIT-")]]
    window = sg.Window('Error!', layout)

    while True:
        event, values = window.read()
        print(event, values)
        if event == sg.WIN_CLOSED or event == '-EXIT-':
            break
    window.close()


def calculate(st1):
    st1 = st1.lower()
    st1 = st1.replace("^", "")
    st1 = st1.replace("**", "")
    st1 = st1.replace(" ", "")
    b1 = st1.find("+-")
    b2 = st1.find("-+")
    b3 = st1.find("--")
    b4 = st1.find("++")
    if b1 != -1 or b2 != -1 or b3 != -1 or b4 != -1:
        errors = "Error:输入表达式当中存在+-或-+或++或--"
        hidden_errors(errors)
        try:
            raise Exception(errors)
        except Exception as e:
            return "error"
    emark = st1.count("=")
    if emark != 1:
        errors = "Error:输入的表达式缺少=或式子当中有多余一个=，程序退出"
        hidden_errors(errors)
        try:
            raise Exception(errors)
        except Exception as e:
            return "error"
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
            if (len(l[i]) > 2):
                errors = "输入的方程无法识别，未知原因，程序退出"
                hidden_errors(errors)
                try:
                    raise Exception(errors)
                except Exception as e:
                    return "error"
            if (l[i][1] != '0' and l[i][1] != '1' and l[i][1] != '2' and l[i][1] != ''):
                errors = "Error:输入的表达式阶数高于二次，程序退出"
                hidden_errors(errors)
                try:
                    raise Exception(errors)
                except Exception as e:
                    return "error"
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
                errors = "输入的方程无法识别，未知原因，程序退出"
                hidden_errors(errors)
                try:
                    raise Exception(errors)
                except Exception as e:
                    return "error"
            if (l[i][1] != '0' and l[i][1] != '1' and l[i][1] != '2' and l[i][1] != ''):
                errors = "Error:输入的表达式阶数高于二次，程序退出"
                hidden_errors(errors)
                try:
                    raise Exception(errors)
                except Exception as e:
                    return "error"
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
            return ("x可取任意实数")
        else:
            return (f'x={-b/c}')
    d = b*b-4*a*c
    if d == 0:
        return (f'x={-b/(2*a)}')
    if d < 0:
        return ("无解")
    if d > 0:
        return (f'x1={(-b+math.sqrt(d))/(2.0*a)},x2={(-b-math.sqrt(d))/(2.0*a)}')


layout = [[sg.Text('Please Input Your Math expression:')],
          [sg.InputText(key='-IN-')],
          [sg.Text("Result:"), sg.Text(key='-OUTPUT-')],
          [sg.Button('calculate', key="-CALCULATE-"), sg.Button('Exit', key="-EXIT-")]]
window = sg.Window('Calculator', layout)

while True:
    event, values = window.read()
    print(event, values)
    if event == sg.WIN_CLOSED or event == '-EXIT-':
        break
    if event == '-CALCULATE-':
        tempvalue = calculate(values["-IN-"])
        window['-OUTPUT-'].update(tempvalue)
    with open("log.txt", mode='a+') as file:
        file.write(f'{values["-IN-"]} {tempvalue}')
        print(file.read())


window.close()
