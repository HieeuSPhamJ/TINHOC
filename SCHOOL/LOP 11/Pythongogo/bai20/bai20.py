name = "bai20"

fi = open(f"{name}.inp")
fo = open(f"{name}.out", "w")

n = int(fi.readline())

s = []

while n:
    n -= 1
    x = int(fi.readline())
    s.append(x)

s.sort(reverse = True)





fo.write(f"Silver = {s[1]}")
