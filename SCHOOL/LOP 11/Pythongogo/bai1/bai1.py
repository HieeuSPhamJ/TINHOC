name = "bai1"

fi = open(f"{name}.inp")
fo = open(f"{name}.out", "w")


a, b = map(int, fi.readline().split())

ta = (a + 1) // 2

tb = (b + 1) // 2

len = abs(ta - tb)

if a < b:
    a = b - len * 2
else:
    a = b + len * 2

# print(a, b)

fo.write(f"{len} ")
fo.write(f"{((a + b) * (len + 1) // 2)}")