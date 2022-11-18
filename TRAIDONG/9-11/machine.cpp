#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int MAXN = 1e6 + 7;
const int base = 30;
const int mod = 1100003357;

int POW[MAXN];
string a[MAXN];
unordered_map<int, int> store;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
}

int dp[MAXN];
int gethash(int l, int r)
{
    return ((dp[r] - dp[l - 1] * POW[r - l + 1]) % mod + mod) % mod;
}

signed main()
{
    // freopen("input.INP", "r", stdin);
    // freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int l, r, d, n;
    cin >> l >> r;
    POW[0] = 1;
    for (int i = 1; i < MAXN; i++)
        POW[i] = (POW[i - 1] * base) % mod;
    int g;
    for (int i = 1; i <= l; i++)
    {
        cin >> a[i];
        if (i == 1)
            g = a[i].length();
        else
            g = gcd(g, a[i].length());
        a[i] = '*' + a[i];
    }

    for (int i = 1; i <= r; i++)
    {
        cin >> d;
        g = gcd(g, d);
    }
    // cout<<g<<endl;
    for (int i = 1; i <= l; i++)
    {
        int hashstore = 0;
        for (int j = 1; j < a[i].length(); j++)
        {
            hashstore = (hashstore * base + (a[i][j] - 'a') + 1) % mod;
            if (j % g == 0)
            {
                store[hashstore]++;
                // cout<<i<<' '<<j<<' '<<hashstore<<endl;
            }
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string t;
        cin >> t;
        t = '*' + t;
        if ((t.length() - 1) % g != 0)
            cout << "No" << endl;
        else
        {
            dp[0] = 0;
            for (int j = 1; j < t.length(); j++)
            {
                dp[j] = (dp[j - 1] * base + (t[j] - 'a') + 1) % mod;
            }
            int last = t.length() - 1;
            for (int j = t.length() - g; j >= 1; j -= g)
            {
                int hashstore = 0;

                hashstore = gethash(j, last);
                // cout<<hashstore<<' '<<last<<' '<<j<<endl;
                if (store[hashstore] > 0)
                {
                    last = j - 1;
                }
            }
            if (last == 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}