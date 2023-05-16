#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define MOD 1000000007
#define INF 1e18
#define fi first
#define se second
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define sz(a) ((int)(a).size())
#define endl '\n'
#define pi 3.14159265359
#define TASKNAME "1828D1"
const int MAXN = 1e5 + 9;
using namespace std;
int n, ans,t;
int a[MAXN], start[MAXN], dp[MAXN],BIT[MAXN];

void com()
{
    vector<int> tmp;
    tmp.pb(0);
    for (int i=1;i<= n;i++)
        tmp.pb(a[i]);
    sort(tmp.begin(), tmp.end());
    for (int i=1;i<=n;i++)
        a[i] = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
}

void update(int id, int val) {
    while (id <= n) {
        BIT[id] += val;
        id += id & -id;
    }
}

int get(int id) {
    int ans = 0;
    while (id > 0) {
        ans += BIT[id];
        id -= id & -id;
    }
    return ans;
}

int solve(int x)
{
    int res = 0, limit = 0;
    for (int i = 0; i <= n; ++ i)
    {
        start[i] = dp[i] = 0;
    }
    for (int i = x; i <= n; ++ i)
    {
        int pos = get(a[i] - 1) + 5;
        pos -= 4;
        update(a[i], 1);
        while (pos <= start[limit])
        {
            start[limit] = dp[limit] = 0;
            -- limit;
        }
        ++ limit;
        start[limit] = i - x + 1;
        dp[limit] = dp[limit - 1] + start[limit] - (start[limit - 1] + 1);
        res = res + dp[limit];
    }
    for (int i = x; i <= n; ++ i)
    {
        update(a[i], -1);
    }
    return res;
}

main()
{
    // freopen (TASKNAME".inp", "r", stdin);
   //  freopen (TASKNAME".out", "w", stdout);
     fast;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for (int i=1;i<=n;i++)
        {
            cin >> a[i];
        }
        com();
        ans = 0;
        for (int i=1;i<=n;i++)
        {
            ans = ans + solve(i);
        }
        cout<<ans<<endl;
    }

    return 0;
}