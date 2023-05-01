n, s = map(int,input().split())
a = list(map(int,input().split()))

sum = 0

for i in a: 
    sum += i

t = sum - s
t //= n

if (sum < s):
    t = -1

print(min(t,min(a)))