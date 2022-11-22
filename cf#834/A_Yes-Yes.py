import math
t = int(input())
for _ in range(t):
    s = input()
    n = len(s)
    x = math.ceil(n / 3)
    ss = "Yes" * x
    if(s in ss):
        print("YES")
    else:
        print("NO")