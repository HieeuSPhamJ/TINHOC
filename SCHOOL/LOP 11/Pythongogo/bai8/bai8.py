name = "bai8"

fi = open(f"{name}.inp")
fo = open(f"{name}.out", "w")

n = int(fi.readline())

ans = ((1 + n) * n) / 2

n -= 1

while n:
    n -= 1   
    x = int(fi.readline())
    ans -= x

fo.write(str(int(ans)))
