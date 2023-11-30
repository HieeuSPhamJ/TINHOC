#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int n, k;
int a[100000];
int mod;

bool cmp(int a, int b)
{
    return (a % mod) > (b % mod);
}

signed main()
{
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    int ma = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    int res = 0;
    for (int b = 1; b <= ma; b++){
        int tres = 0;
        for (int i = 0; i < n; i++){
            tres += a[i] / b;
        }
        if (tres < k / 2){
            break;
        }
        if (tres >= k){
            res = max(res, b * (k / 2));
            continue;
        }
        mod = b;
        sort(a, a + n, cmp);
        int cur = b * (tres - k / 2);
        for (int i = 0; i < n and i + tres < k; i++){
            cur += a[i] % b;
        }
        res = max(res, cur);
    }
    cout << res << endl;
}