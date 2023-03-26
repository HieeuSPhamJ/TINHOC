x = int(input())
n = int(input())
lists = []
ans = x * (n + 1)
while n:
    n -= 1
    t = int(input())
    ans -= t
    
print(ans)
    