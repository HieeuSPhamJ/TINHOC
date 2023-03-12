name = "bai13"

fi = open(f"{name}.inp")
fo = open(f"{name}.out", "w")

ans = 0

while 1: 
    x = int(fi.readline())
    if x == 0:
        break
    ans += 1

fo.write(f"{ans}")
