text = input()
alph = 'aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ'
sign = ',.?! -"'
text = text.split()
for i in range(len(text)):
    text[i] = list(text[i])
    for j in range(len(text[i])):
        t_str = ''.join(text[i])
        k = alph.find(text[i][j]) + len(t_str.strip(sign))*2
        if k >= len(alph):
            k = k - len(alph)
        if text[i][j] in sign:
           text[i][j] = text[i][j]
        else:
            text[i][j] = alph[k]           
    text[i] = ''.join(text[i])
text = ' '.join(text)
print(text)
