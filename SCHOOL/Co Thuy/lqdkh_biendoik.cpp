#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];
unordered_map <int,int> Count;
int conv[maxN];
int pre[maxN];
int suf[maxN];
int num[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    set <int> s;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        Count[a[i]]++;
        s.insert(a[i]);
    }
    n = 1;
    for (auto i: s){
        conv[n] = i;
        n++;
    }
    n--;
    for (int i = 1; i <= n; i++){
        num[i] = num[i - 1] + Count[conv[i]];
        pre[i] = pre[i - 1] + num[i - 1] * abs(conv[i] - conv[i - 1]);
        // cout << pre[i] << " " << num[i] << endl;
    }
    // for (int i = 1; i <= n; i++){
    //     cout << num[i] << " ";
    // }
    // cout << endl;
    for (int i = n; i >= 1; i--){
        suf[i] = suf[i + 1] + (num[n] - num[i]) * abs(conv[i] - conv[i + 1]);
        // cout << suf[i] << " " << num[n] - num[i] << endl;
    }

    int ans = 1e18;
    for (int i = 1; i <= n; i++){
        int cnt = Count[conv[i]];
        if (cnt >= k){
            ans = 0;
            break;
        }
        int res = 1e18;

        int t1 = 1e18;
        int t2 = 1e18;
        int t3 = 1e18;

        // cout << "With: " << conv[i] << endl;
        if (k - cnt <= num[i - 1]){
            t1 = pre[i - 1] + abs(conv[i] - conv[i - 1]) * (k - cnt);
        }

        if (k - cnt <= num[n] - num[i]){
            // cout << suf[i + 1] << " " << abs(conv[i] - conv[i + 1]) << " " << (k - cnt) << endl;
            t2 = suf[i + 1] + abs(conv[i] - conv[i + 1]) * (k - cnt);
        }

        int v1 = abs(conv[i] - conv[i - 1]);
        int v2 = abs(conv[i] - conv[i + 1]);

        int n1 = min(k - cnt, num[i - 1]);
        int n2 = min(k - cnt, num[n] - num[i]);

        t3 = min(t3, v1 * n1 + v2 * (k - cnt - n1));
        t3 = min(t3, v2 * n2 + v1 * (k - cnt - n2));

        res = min({t1,t2,t3 + pre[i - 1] + suf[i + 1]});

        ans = min(ans, res);
    }

    cout << ans << endl;

    return 0;
}