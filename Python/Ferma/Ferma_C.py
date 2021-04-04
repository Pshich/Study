from ctypes import *
import time
time1 = time.time()
# Загружаем библиотеку
Function = CDLL('./Ferma.so')

res = Function.main()
print(res)
time2 = time.time()
print('Время выполнения программы:', time2 - time1)
