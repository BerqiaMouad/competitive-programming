n = int(input())
new_n = bin(n)
size = len(new_n)

out = "0" * size


res = []
res.append(int(out, 2))

def f(j, temp, tp):
    if(j == 0):
        return
    for i in range(j, 0, -1):
        if(temp[i] == '1'):
            res.append(int(tp[:i] + '1' + tp[i+1:], 2))
            f(i-1, temp, tp[:i] + '1' + tp[i+1:])

for i in range(size-1, 0, -1):
    if(new_n[i] == '1'):
        temp = new_n[i:size]
        tp = "0" * len(temp)
        tp = '1' + tp[1:]
        res.append(int(tp, 2))
        f(len(temp) - 1, temp, tp)
res = sorted(res)
for i in res:
    print(i)