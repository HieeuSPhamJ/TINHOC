#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(t1) t1.begin(), t1.end()
using namespace std;

const int mod = 998244353;
const int maxN = 1000010;

int inv[maxN];

int add(int a, int b)
{
    return (a + b) % mod;
}
int subtr(int a, int b)
{
    return ((a + mod) - b) % mod;
}
int mul(int a, int b)
{
    return (a % mod * b % mod) % mod;
}

void init()
{
    inv[0] = 1;
    inv[1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        inv[i] = mod - mod / i * inv[mod % i] % mod;
    }
}

int a[maxN] , b[maxN] , c[maxN];

signed main()
{
    // freopen("input.INP", "r", stdin);
    // freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int test;
    cin >> test;
    while (test--)
    {
        int q , n , m , x , y;
        cin >> n;
        int sum = 0;
        int mini = 1e18;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if(i >= 2)
                mini = min(mini , a[i] + a[i - 1]);
            sum += a[i];
        }
        cout << sum - mini - mini << endl;
    }
    return 0;
}