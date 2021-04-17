n = int(input())
m = int(input())
fib_list = [0, 1, 1]
piz_list = [0, 1%m, 1%m]
a = 0
for i in range(3, 6*m + 1):
    fib_list.append(fib_list[i - 1] + fib_list[i - 2])
    piz_list.append((fib_list[i - 1] + fib_list[i - 2])%m)
    a = len(piz_list)
    if a % 2 == 0:
        a /= 2
        a = int(a)
        if piz_list[:a] == piz_list[a:]:
            piz_list = piz_list[:a]
            break
print(piz_list[n%a])
