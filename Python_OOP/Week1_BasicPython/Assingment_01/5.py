import pyautogui
from time import sleep
n=int(input())
sleep(5)
for i in range(0,n+1):
    for j in range(0,i):
        pyautogui.write('# ')
    pyautogui.write('\n')

