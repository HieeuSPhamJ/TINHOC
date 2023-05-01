n, a , b = map(int, input().split())

arr = list(map(int, input().split()))

ls = {}
cost = {}
cost[0] = a
cost[1] = b

for i in range(0,n):
    ls[i] = arr[i]

mi = 0
if a > b:
    mi = 1
    
ok = 1
res = 0

for i in range(0,n):
    if ls[i] == 2:
        if ls[n - i - 1] == 2:
            ls[i] = mi
            ls[n - i - 1] = mi
            res += cost[mi] + cost[mi]
            if i == n - i - 1:
                res -= cost[mi]
        else:
            ls[i] = ls[n - i - 1]
            res += cost[ls[n - i - 1]]
    if (not ls[i] == 2) and (not ls[n - i - 1] == 2):
        if ls[i] != ls[n - i - 1]:
            ok = 0
            
if ok:
    print(int(res))
else:
    print(-1)
            
            
