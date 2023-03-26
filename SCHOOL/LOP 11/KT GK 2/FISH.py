n = int(input())
x = int(input())

ans = 0

while n:
    n -= 1
    lists = list(map(int,input().split()))
    if abs(lists[0] - lists[1]) <= x:
        # print("take", lists[0], lists[1], abs(lists[0] - lists[1]), x)
        ans += max(lists[0], lists[1])
    else:
        # print("new")
        t = int(input())
        ans += t
print(ans)