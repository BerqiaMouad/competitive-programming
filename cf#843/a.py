t = int(input())

for _ in range(t):
    s = input()
    n = len(s)
    ok = False
    for i in range(1, n - 1):
        for j in range(i+1, n):
            a = [s[0:i], s[i:j], s[j:]]
            if((a[0] <= a[1] and a[1] >= a[2]) or (a[0] >= a[1] and a[1] <= a[2])):
                print(" ".join(a))
                ok = True
                break
        if(ok):
            break