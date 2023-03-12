name = "bai11"

fi = open(f"{name}.inp")
fo = open(f"{name}.out", "w")

n = int(fi.readline())

from math import log2

fo.write(f"{int(log2(n))} {2 ** int(log2(n))}")