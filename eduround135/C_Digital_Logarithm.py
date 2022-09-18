t = int(input())

for _ in range(t):

    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    res = 0

    for i in range(len(a)):
        if(a[i] > 10):
            a[i] = len(str(a[i]))
            res +=1
    for i in range(len(b)):
        if(b[i] > 10):
            a[i]