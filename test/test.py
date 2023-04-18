t = int(input())

def cal(n):
    if (n == 0):
        return 0
    if (n == 1):
        return -1
    sumle = n
    sumchan = n
    if (n % 2 == 1):
        sumle = n
        sumchan = n - 1
    else:
        sumle = n - 1
        sumchan = n
    res = (sumchan + 2) * (sumchan // 2)
    res -= (sumle + 1) * (sumle // 2 + 1)
    res //= 2
    return res
while t:
    t -= 1
    l, r = map(int,input().split())
    
    print(cal(r) - cal(l - 1), end = ' ')
    