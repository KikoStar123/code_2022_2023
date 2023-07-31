'''
Author: error: git config user.name && git config user.email & please set dead value or install git
Date: 2022-11-15 13:14:27
LastEditors: error: git config user.name && git config user.email & please set dead value or install git
LastEditTime: 2022-11-15 13:16:28
FilePath: \CODE\Python\zbx_wx\GUI\gui1.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import PySimpleGUI as sg

layout = [
    [sg.Text('Enter a text:')],
    [sg.InputText(key='-TEXT INPUT-')],
    [sg.Button('OK', key='-OK-'), sg.Button('Cancel')]
]
window = sg.Window('Hello', layout)

event, values = window.read()
window.close()

if event == '-OK-':
    sg.Window(
        'Result',
        [[sg.Text("You wrote: " + values['-TEXT INPUT-'])], [sg.Button('OK')]]
    ).read(close=True)
