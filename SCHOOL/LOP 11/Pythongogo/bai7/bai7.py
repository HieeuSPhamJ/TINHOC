name = "bai7"

fi = open(f"{name}.inp")
fo = open(f"{name}.out", "w")

n = int(fi.read())

i = 1
res = 0

while i * i <= n:
    n -= i * i
    res += 1
    i += 1
        
fo.write(str(res))