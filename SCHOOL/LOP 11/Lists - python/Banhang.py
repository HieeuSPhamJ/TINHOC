n, c = map(int, input().split())

ans = 10**10

while n:
    n -= 1
    
    p, d, v = map(int, input().split())
    # print(ans, p + v * c + d)
    ans = min(ans, p + v * c + d)
    
print(ans)