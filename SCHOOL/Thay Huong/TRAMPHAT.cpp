#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int cal(ii i, ii j){
    return (pow(i.fi - j.fi, 2) + pow(i.se - j.se, 2));
}

const int maxN = 1e3 + 10;

int rt[maxN];

int find(int nu){
    if (nu == rt[nu]){
        return nu;
    }
    return rt[nu] = find(rt[nu]);
}

signed main(){
    freopen("TRAMPHAT.INP", "r", stdin);
    freopen("TRAMPHAT.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <ii> ls;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        ls.push_back({x,y});
        rt[i] = i;
    }
    vector <pair<int,ii>> els;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            els.push_back({cal(ls[i], ls[j]), {i,j}});
        }
    }   
    sort(all(els));
    int res = 0;
    for (auto e: els){
        int a = e.se.fi;
        int b = e.se.se;
        int v = e.fi;
        a = find(a);
        b = find(b);
        if (a == b){
            continue;
        }
        rt[a] = b;
        res = max(res, v);
    }
    cout << fixed << setprecision(7) << sqrtl(res) / 2.0 << endl;
    return 0;
}