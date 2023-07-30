#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e3 + 10;

map <ii,ii> rt;
int mar[maxN][maxN];

ii find(ii a){
    if (rt[a] == a){
        return a;
    }
    return rt[a] = find(rt[a]);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                rt[{i,j}] = {i,j};
            }
        }
        for (int i = 1; i <= k; i++){
            ii a, b;
            cin >> a.fi >> a.se >> b.fi >> b.se;
            ii u = find(a);
            ii v = find(b);
            if (u == v){
                continue;
            }
            rt[u] = v;
        }

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                find({i,j});
            }
        }
        int ok = 1;
        for (int i = 2; i <= n; i++){
            for (int j = 2; j <= m; j++){
                set <ii> s;
                s.insert(rt[{i,j}]);
                s.insert(rt[{i + 1,j}]);
                s.insert(rt[{i,j + 1}]);
                s.insert(rt[{i + 1,j + 1}]);
                if (s.size() < 3){
                    ok = 0;
                }
            }
        }

    }
    return 0;
}