n = 0
s = 0
a = []

def cal1():
    sum = 0

    for i in a:
        sum += i

    t = sum - s
    t //= n

    if (sum < s):
        t = -1

    return min(t,min(a))

def cal2():
    l = 0
    r = min(a)
    res = -1
    while l <= r:
        mid = (l + r) // 2
        sum = 0
        for i in a:
            sum += i - mid
        # print(l, r, mid, sum)
        if (sum >= s):
            l = mid + 1
            res = mid
        else:
            r = mid - 1
    return res

import random

for t in range(1,10000):  
    n = random.randint(1,1000)
    s = random.randint(2,10000)
    a.clear()
    for i in range(n):
        a.append(random.randint(1,100))
    print(n,s)
    print(a)
    # print(cal1(), cal2())
    if cal1() != cal2():
        print("#######")
        break