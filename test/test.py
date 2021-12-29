import random

n = random.randint(100, 1000000)
m = random.randint(100, 1000000)

print(n)
print(m)

print(random.randint(100, n))
print(random.randint(100, m))
print(random.randint(100, n))
print(random.randint(100, m))