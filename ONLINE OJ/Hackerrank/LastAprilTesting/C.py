def calPow(x, y):
    # if y == 0:
    #     return 1
    # temp = calPow(x, y / 2)
    # if y % 2 == 0:
    #     return temp * temp
    # return temp * temp * x
    ans = 1
    while y > 0:
        if y % 2 == 1:
            ans = ans * x
        x = x * x
        y = int(y / 2)
    return ans


test = input()
test = int(test)
# print(test)
for i in range(test):
    inp = input().split()
    a = int(inp[0])
    b = int(inp[1])
    c = int(inp[2])
    # print(c)
    print(((1 - calPow(a, b + 1)) / (1 - a)) % c)

# print(calPow(2, 10))