#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e6 + 10;

int a[maxN];
int l[maxN];
int r[maxN];

bool cmp(ii a, ii b){
    if (a.fi == b.fi){
        return a.se < b.se;
    }
    return a.fi > b.fi;
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
    int n;
    cin >> n;
    vector <ii> ls;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        l[i] = i - 1;
        r[i] = i + 1;
        ls.push_back({a[i], i});
    }
    l[1] = 0;
    r[n] = 0;
    sort(all(ls), cmp);
    int res = 0;
    for (auto i: ls){
        res += a[i.se] + a[l[i.se]] + a[r[i.se]];
        // cout << i.se << " " << l[i.se] << " " << r[i.se] << endl;
        r[l[i.se]] = r[i.se];
        l[r[i.se]] = l[i.se];
    }
    cout << res << endl;
    return 0;
}