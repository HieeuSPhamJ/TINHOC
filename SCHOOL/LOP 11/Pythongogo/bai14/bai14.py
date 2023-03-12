name = "bai14"

fi = open(f"{name}.inp")
fo = open(f"{name}.out", "w")

ans = 0

while 1: 
    x = int(fi.readline())
    ans += x
    if x == 0:
        break

fo.write(f"Sum = {ans}")
