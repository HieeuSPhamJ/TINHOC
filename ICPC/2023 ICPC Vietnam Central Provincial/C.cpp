#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

int pow(int a, int b)
{
    if (b == 1)
    {
        return a;
    }
    if (b == 0)
    {
        return 1;
    }
    int t = pow(a, b / 2);
    (t *= t) %= mod;
    if (b % 2)
    {
        (t *= a) %= mod;
    }
    return t;
}

const int maxN = 79;

int mul[maxN];
int set_mul[maxN];

signed main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        memset(mul,0,sizeof(mul));
        memset(set_mul,0,sizeof(set_mul));
        
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            mul[x]++;
        }

        for (int i = 1; i < maxN; i++)
        {
            for (int j = i + i; j < maxN; j += i){
                (mul[i] += mul[j]) %= mod;
            }
        }
        for (int i = 1; i < maxN; i++)
        {
            (set_mul[i] = pow(2, mul[i]) - 1 + mod) %= mod;
        }

        for (int i = maxN - 1; i >= 1; i--)
        {
            for (int j = i + i; j < maxN; j += i)
            {
                (set_mul[i] = set_mul[i] - set_mul[j] + mod) %= mod;
            }
        }
        int ans = 0;
        for (int i = 1; i < maxN; i++)
        {
            (ans = ans + set_mul[i] * i) %= mod;
        }
        cout << ans << endl;
    }
}
