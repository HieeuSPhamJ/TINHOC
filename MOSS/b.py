from math import *
r, x, y, x1, y1 = map(int, input().split())
d = sqrt((x1 - x)**2 + (y1 - y)**2)
if d % (2*r) == 0:
    print(int((d//(2*r))))
else:
    print((int(d//(2*r)+1)))