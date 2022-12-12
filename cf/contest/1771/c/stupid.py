import math
t = int(input())

for _ in range(t):
    n=int(input())
    a = list(map(int, input().split()))
    lcm = 1
    mul = 1
    for i in range(n):
        mul *= a[i]
        lcm = a[i] * lcm // math.gcd(lcm, a[i])
    if mul==lcm:
        print("NO")
    else:
        print("YES")

