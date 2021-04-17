m = int(input())
n = int(input())
temp = 0
while m > 0:
    if m % n == 0:
        break
    else:
        temp = m % n
        m = n
        n = temp
print(n)
