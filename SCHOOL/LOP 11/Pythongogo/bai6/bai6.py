from math import sqrt

name = "bai6"

fi = open(f"{name}.inp")
fo = open(f"{name}.out", "w")

n = int(fi.read())


def isPrime(n):
    ok = 0
    if(n > 1):
        for i in range(2, int(sqrt(n)) + 1):
            if (n % i == 0):
                ok = 1
                break
        if (ok == 0):
            return "Yes"
        else:
            return "No"
    return "No"


fo.write(isPrime(n))