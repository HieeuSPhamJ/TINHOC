//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define taskname "blabla"
#define endl "\n"
#define X first
#define Y second
#define int long long
#define Ha dethuong

using namespace std;
typedef pair <int, int> ii;
const long long oo = 1e18 + 3;
const long long mod = 998244353;
const int N = 4e1 + 3;

int l, r, k, temp, ans, limit;
int p2[40], p3[40];
long long fact[N], infact[N];

long long add(long long a, long long b)
{
    return (a + b) % mod;
}

long long mul(long long a, long long b)
{
    return (a * b) % mod;
}

long long sub(long long a, long long b)
{
    return ((a - b) % mod + mod) % mod;
}

long long Power(long long a, long long b)
{
    long long res = 1;
    long long curr = a % mod;
    while (b > 0)
    {
        if (b & 1)
        {
            res = mul(res, curr);
        }
        curr = mul(curr, curr);
        b >>= 1;
    }
    return res;
}

void init()
{
    fact[0] = 1;
    for (long long i = 1; i < N; ++ i)
    {
        fact[i] = mul(fact[i - 1], i);
    }
    infact[N - 1] = Power(fact[N - 1], mod - 2);
    infact[0] = 1;
    for (long long i = N - 2; i >= 1; -- i)
    {
        infact[i] = mul(infact[i + 1], i + 1);
    }
}

long long C(long long k, long long n)
{
    return mul(fact[n], mul(infact[k], infact[n - k]));
}

signed main()
{
//   freopen (taskname".inp", "r", stdin);
//   freopen (taskname".out", "w", stdout);


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    p2[0] = p3[0] = 1;
    for (int i = 1; i <= 25; ++ i)
    {
        p2[i] = p2[i - 1] * 2;
        p3[i] = p3[i - 1] * 3;
    }

    int Test;
    cin >> Test;
    for (int TestCase = 1; TestCase <= Test; ++ TestCase)
    {
        cin >> l >> r;
//        l = 250001, r = 1000000;
        temp = l;
        ans = k = 0;
        while ((temp * 2) <= r)
        {
            ++ k;
            temp <<= 1;
        }
        cout << k << endl;
        for (int j = k; j >= 0; -- j)
        {
            limit = r / (p2[j] * p3[k - j]);
            if (limit < l)
            {
                break;
            }
            cout << ans << " " << limit - l + 1 << " " << C(j, k) << endl;
            ans = add(ans, mul(limit - l + 1, C(j, k)));
        }
        cout << k + 1 << ' ' << ans << endl;
    }

    return 0;
}
