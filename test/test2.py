import math
r, x1, y1, x2, y2 = map(int, input().split())

len = math.sqrt((x1 - x2)**2 + (y1 - y2)**2)

len -= r * 2

t = (len // (r * 2))

if t * r * 2 < len:
    t += 1
    
t += 1
    
print(int(t + 1))