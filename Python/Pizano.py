n,m = input().split()
n = int(n)
m = int(m)
fib_list = [0, 1, 1]
piz_list = [0, 1%m, 1%m]
a = 0
for i in range(3, 6*m + 1):
    fib_list.append(fib_list[-1] + fib_list[-2])
    piz_list.append((fib_list[-2] + fib_list[-3])%m)
    fib_list.pop(-3)
    if piz_list[-1] == 1 and piz_list[-2] == 0:
        break
if len(piz_list) == 6*m + 1:
    a = 6*m
else:
    a = len(piz_list) - 2
print(piz_list[n%a])
