#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 2e5 + 10;

int n;
int a[maxN];
int la[maxN];
vector <ii> ls1, ls2;

void init(){
    for (int i = 1; i <= n; i++){
        la[i] = 0;
    }
    la[a[1]] = 1;
    for (int i = 2; i <= n; i++){
        int l = la[a[i]] + 1;
        if (l != i){
            ls2.push_back({l,i});
        }
        la[a[i]] = i;
    }
    for (int i = 1; i <= n; i++){
        la[i] = n + 1;
    }
    la[a[n]] = n;
    for (int i = n - 1; i >= 1;i--){
        int r = la[a[i]] - 1;
        if (r != i){
            ls1.push_back({i,r});
        }
        la[a[i]] = i;
    }

    // for (int i = 1; i <= n; i++){
    //     cout << l[i] << " " << r[i] << endl;
    // }
}

bool cmp(ii a, ii b){
    return a.se > b.se;
}

int bit[2][maxN];

void update(int t, int i, int v){
    while(i <= n){
        bit[t][i] += v;
        i += i & (-i);
    }
}

int get(int t, int i){
    int res = 0;
    while(i){
        res += bit[t][i];
        i -= i & (-i);
    }
    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    init();
    
    sort(all(ls1), cmp);
    sort(all(ls2), cmp);
    // cout << "=ls1=" << endl;
    // for (auto i: ls1){
    //     cout << i.fi << " " << i.se << endl;
    // }
    // cout << "=ls2=" << endl;
    // for (auto i: ls2){
    //     cout << i.fi << " " << i.se << endl;
    // }
    int res = 0;

    for (int i = 1; i <= n; i++){
        // cout << "With: " << i << endl;
        while(ls2.size() and ls2.back().se == i){
            ii t = ls2.back();
            ls2.pop_back();
            // cout << "add " << t.fi << ' ' << t.se << endl;
            update(0,t.fi,1);
            update(1,t.se,1);
        }
        // for (int i = 1; i <= n; i++){
        //     cout << get(0,i) - get(0,i - 1) << " ";
        // }
        // cout << endl;
        // for (int i = 1; i <= n; i++){
        //     cout << get(1,i) - get(1,i - 1) << " ";
        // }
        // cout << endl;
        while(ls1.size() and ls1.back().se == i){
            ii t = ls1.back();
            ls1.pop_back();
            int ans = get(0,t.fi) - get(1,t.fi);
            // cout << t.fi << " " << t.se << ": " << ans << endl;
            res += ans;
        }
    }
    cout << res << endl;
    return 0;
}