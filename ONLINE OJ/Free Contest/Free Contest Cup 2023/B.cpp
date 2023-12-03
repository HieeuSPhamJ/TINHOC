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

const int maxN = 1e5 + 10;

ii a[maxN];
int pre[maxN];

bool cmp(ii x , ii y){
    return x.se > y.se;
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
    int n, m;
    cin >> n >> m;
    vector <int> ls;
    for (int i = 1; i <= m; i++){
        cin >> a[i].fi >> a[i].se;
        ls.push_back(a[i].fi);
    }
 
    sort(a + 1 , a + 1 + m, cmp);
    sort(all(ls));

    // for (auto i: ls){
    //     cout << i << endl;
    // }
 
    int res = 0;
    if(n <= m){
        for (auto i: ls){
            res += i;
        }
    }
    int sum = 0;
    for (int i = 1; i <= m and n; i++){
        while(n and ls.size() and a[i].se <= ls.back()){
            sum += ls.back();
            ls.pop_back();
            n--;
        }
        int cost = a[i].se * n;
        if(ls.empty() or a[i].fi >= ls.back()){
            res = max(res, sum + cost);
        }
        else{
            res = max(res, sum + cost - a[i].se + a[i].fi);
        }
    }
    cout << res;
    return 0;
}

/*
a1 + b1 * (x1 - 1)
a1 * x1 + b1 * x1
*/