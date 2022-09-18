t = int(input())

for i in range(t):
    print("Case #" + str(i+1) + ": ", end="")
    n = int(input())
    ada = []
    charles = []
    for j in range(n):
        temp = input().split()
        name = temp[0]
        d = int(temp[1])
        u = int(temp[2])

        ada.append((name, u, d))
        charles.append((d, u, name))
    
    ada = sorted(ada, key=lambda x: (x[0], x[1]))
    charles = sorted(charles, key=lambda x: (x[0], x[1]))

    cnt = 0

    for j in range(n):
        if(ada[j][1] == charles[j][1]):
            cnt+=1
    
    print(cnt)