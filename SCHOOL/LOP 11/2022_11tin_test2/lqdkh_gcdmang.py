n = int(input())

GCD = 0
ONE = 0

from math import gcd

li = list(map(int,input().split()))

for x in li:
    if x == 1:
        ONE += 1
    else: 
        GCD = gcd(GCD,x)
        
if gcd != 1 and ONE == 0:
    print(0)
else:
    n = len(li)
    cnt = 0
    for i in range(0,n - 1):
        if li[i] == 1:
            li[i] = 0
            li[i + 1] += 1
        cnt += 1
    if li[n - 1] == 1:
        li[n - 1] += li[n - 2]
        cnt += 1
    print(cnt)
    
# gcd(a,b) = gcd(a - b, a) = gcd(a,b + a)
