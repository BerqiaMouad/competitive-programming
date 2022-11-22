import math

res = []

def f(n, m, sz, origsz):
    res.append(n * m)
    if(sz < 0):
        return
    if(origsz == sz):
        for i in range(int(str(m)[sz]) + 1):
            f(n, int(str(m)[:sz] + str(i) + str(m)[sz+1:]), sz-1, origsz)
    else:
        for i in range(6):
            f(n, int(str(m)[:sz] + str(i) + str(m)[sz+1:]), sz-1, origsz)

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    sz = len(str(m)) - 1
    f(n, m, sz, sz)
    res = sorted(res)[::-1]
    # print(res)
    zero_cnt = 0
    result = -1
    for i in res:
        cnt = 0
        temp = str(i)
        ind = len(temp) - 1
        while(ind >= 0 and temp[ind] == '0'):
            cnt += 1
            ind -= 1
        if(cnt > zero_cnt):
            zero_cnt = cnt
            result = i
    if(result > 0):
        print(result)
    else:
        print(res[0])
    res.clear()