n, a, b, c = map(int, input().split())

k = (n * a + b)
k //= (a+b)

if (max((n-k)*a, (k-1)*b)+k*c > max((n-(k+1))*a, (k*b))+(k+1)*c):
    print(k + 1)
else:
    print(k)
 