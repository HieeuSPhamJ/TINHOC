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

ii a[maxN];

bool cmp(ii x, ii y){
    return x.se < y.se;
}

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi;
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i].se;
    }
    vector <ii> t1,t2;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        if (a[i].fi >= a[i].se){
            t1.push_back(a[i]);
        }
        else{
            t2.push_back(a[i]);
        }
        sum += abs(a[i].fi - a[i].se);
    }
    sort(all(t1));
    vector <ii> t3;
    if(!t1.empty()){
        t3.push_back(t1[0]);
        t3.push_back(t1.back());
    }
    sort(all(t1), cmp);
    if(!t1.empty()){
        t3.push_back(t1[0]);
        t3.push_back(t1.back());
    }
    sort(all(t2));
    if(!t2.empty()){
        t3.push_back(t2[0]);
        t3.push_back(t2.back());
    }
    sort(all(t2), cmp);
    if(!t2.empty()){
        t3.push_back(t2[0]);
        t3.push_back(t2.back());
    }

    int res = sum;

    for (auto i: t3){
        for (auto j: t3){
            res = max(res , sum - abs(i.fi - i.se) - abs(j.fi - j.se) + abs(i.fi - j.se) + abs(j.fi - i.se));
        }
    }

    cout << res << endl;
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
    int test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}