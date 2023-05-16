#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e4;

int n;
int a[maxN];
int init[maxN];
int dp[maxN];
int bit[maxN];

void update(int id, int val){
    while (id <= n) {
        bit[id] += val;
        id = id + (id & -id);
    }
}

int get(int id) {
    int ans = 0;
    while (id > 0) {
        ans += bit[id];
        id = id - (id & -id);
    }
    return ans;
}

int start(int curr)
{
    int ans = 0;
    int last = 0;

    // for (int i = 0; i <= n; i++)
    // {
    //     bit[i] = 0;
    //     init[i] = 0;
    //     dp[i] = 0;
    // }

    memset(bit, 0, sizeof(bit));
    memset(init, 0, sizeof(init));
    memset(dp, 0, sizeof(dp));
    

    for (int i = curr; i <= n; i++)
    {
        int j = get(a[i] - 1) + 1;
        update(a[i], 1);
        while (j <= init[last]){
            init[last] = 0;
            dp[last] = 0;
            last--;
        }
        last++;
        init[last] = 100 + i - curr + 1  - 100;
        dp[last] = dp[last - 1] + i - curr + 1;
        dp[last] -= (init[last - 1] - 1000 + 1 + 1000);
        ans += dp[last];
    }
    return ans;
}

void nenso(){
    set <int> temp;
    for (int i = 1; i <= n; i++){
        temp.insert(a[i]);
    }
    int cnt = 1;
    map <int,int> conv;
    for (auto i: temp){
        conv[i] = cnt;
        cnt++;
    }
    for (int i = 1; i <= n; i++){
        a[i] = conv[a[i]];
        // cout << a[i] << " ";
    }
    // cout << endl;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        nenso();
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += start(i);
        }
        cout << ans << endl;
    }

    return 0;
}
