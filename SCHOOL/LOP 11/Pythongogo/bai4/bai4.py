name = "bai4"

# fi = open(f"{name}.inp")
fo = open(f"{name}.out", "w")


count = 0

for i in range(100, 10000):
    s = str(i)
    t = 0
    for d in s:
        t += int(d) ** len(s)
    
    if t == i:
        # print(s)
        count += 1

fo.write(str(count))