import time
import ctypes
time1 = time.time()
flag=False
for a in range(3, 151):
    a5 = a ** 5
    for b in range(a, 151):
        b5 = b ** 5
        sum_ab = a5 + b5
        for c in range(b, 151) :
            c5 = c ** 5
            sum_abc = sum_ab + c5
            for d in range(c, 151):
                d5 = d ** 5
                e = int((sum_abc + d5) ** 0.2)
                if sum_abc +d5 == e ** 5:
                    print('a =', a, 'b =', b, 'c =', c, 'd =', d, 'e=', e)
                    print(a + b + c + d + e)
                    flag=True
    if flag == True:
        break
time2 = time.time()
print('Время выполнения программы:', time2 - time1)
