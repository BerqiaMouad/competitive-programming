t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    s = s.lower()
    ss = s[0]

    # merge consecutive same characters
    for i in range(1, n):
        if s[i] != s[i-1]:
            ss += s[i]

    if(ss == 'meow'):
        print('YES')
    else:
        print('NO')
