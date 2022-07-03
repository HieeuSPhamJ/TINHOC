import random

n = 20
k = 10

inf = 1000

print(f"{n} {k}")

listA = []

for i in range(1, n + 1):
    a = random.randint(1, 100)
    listA.append(a)

for i in listA:
    print(i, end = " ")

print()

for i in range(1, k + 1):
    l = random.randint(1, n)
    r = random.randint(1, n)
    print(f"{min(l, r)} {max(l, r)}")
