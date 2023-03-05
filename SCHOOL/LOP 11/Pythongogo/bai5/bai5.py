name = "bai5"

fi = open(f"{name}.inp")
fo = open(f"{name}.out", "w")

n = int(fi.read())

i = 1
res = 0

while i * i <= n:
    # print(n, i * i, n % (i * i))
    if n % (i * i) == 0:
        res = max(res, i * i)
    i += 1
        
fo.write(str(res))