name = "bai3"

fi = open(f"{name}.inp")
fo = open(f"{name}.out", "w")


a, b, c, v0, v1, v2 = map(int, fi.readline().split())

a = min(a,b + c)
b = min(b,a + c)

ans = a / v0 + a / v1 + b / v0 + b / v1

tans1 = a / v0 + c / v1 + b / v2

tans2 = b / v0 + c / v1 + a / v2


fo.write(str(min([ans,tans1,tans2])))
