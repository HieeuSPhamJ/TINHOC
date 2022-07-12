import os
import random

def output(name : str):
    dir = "d:\TINHOC\CodeChecker\Code\"
    command = f"""cd {dir} && g++ {name}.cpp -o {name} && {dir}{name}"""
    os.system(command)

def genInput():
    f = open("./input.inp", "w")
    n = 10
    k = 5
    inf = 10
    f.write(f"1\n")
    f.write(f"{n} {k} \n")
    listA = []
    for i in range(1, n + 1):
        a = random.randint(1, n)
        listA.append(a)

    random.shuffle(listA)
    for i in listA:
        f.write(f"{i} ")
    for i in range(1, k + 1):
        l = random.randint(1, n)
        r = random.randint(1, n)
        f.write(f"\n{min(l, r)} {max(l, r)}")
    f.close()

test = 100

while test >= 0:
    genInput()
    output("p1")
    output("p2")
    p1 = open("./out1.txt", mode = 'r')
    p2 = open("./out2.txt", mode = 'r')
    p1out = p1.read()
    p2out = p2.read()
    p1.close
    p2.close
    print("--------")
    print(f"ME: {p1out}")
    print(f"CK: {p2out}")
    if not p1out == p2out:
        print("------")
        break

    test -= 1
    
# genInput()
