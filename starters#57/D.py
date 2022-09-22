from audioop import reverse


t = int(input())

for _ in range(t):
    n = int(input())
    s = input()
    l = ""
    plus = 0
    minus = 0
    for i in s:
        if(i.isdigit()):
            l += i
        elif(i == '+'):
            plus+=1
        else:
            minus+=1
    l = sorted(l)
    l = l[::-1]
    # 12345
    k = ''.join(l[0:len(l) - plus - minus])
    print(k, end="")
    ll = l[len(l)-plus-minus: len(l) - minus]
    stuff = '+'.join(ll)
    if(plus > 0): print("+" + stuff, end="")
    lll = l[len(l) - minus: len(l)]
    stuff = '-'.join(lll)
    if(minus > 0): print("-"+stuff, end="")
    print()

    
