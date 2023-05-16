a, b = map(int, input().split())

res = b - a
res = list(str(res))
if res[0] == '9':
    res[0] = '8'
else:
    res[0] = '9'

print(''.join(res))