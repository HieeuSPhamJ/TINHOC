def fact(n):
    res = 1
    for i in range(1,n + 1):
        res *= i
    return res
    
def C(n,k):
    return fact(n) / (fact(k) * fact(n - k))

def cal(x, n):
    res = 0
    for k in range(x, n + 1):
        res += (fact(n) * ((1/4) ** k) * ((3/4) ** (n - k))) / (fact(k) * fact(n - k))
    return res * 100



for x in range(6):
    n = 40
    print(f"đã chọn đúng {x} câu, lụi {n - x}: {cal(5 - x, n - x)}")