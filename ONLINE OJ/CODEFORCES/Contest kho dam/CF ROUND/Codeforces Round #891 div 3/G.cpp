#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int mod = 998244353;
const int maxN = 2e5 + 10;

int rt[maxN];
int va[maxN];

int find(int i){
    if (i == rt[i]){
        return i;
    }
    return rt[i] = find(rt[i]);
}

int fastpow(int n, int a){
    if (a == 0){
        return 1;
    }
    if (a == 1){
        return n;
    }
    int t = fastpow(n, a / 2);

    (t *= t) %= mod;
    
    if (a % 2){
        (t *= n) %= mod;
    }
    return t;
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
        int n, up;
        cin >> n >> up;
        vector <pair<int,ii>> ls;
        for (int i = 1; i <= n; i++){
            rt[i] = i;
            va[i] = 1;
        }
        
        for (int i = 1; i < n; i++){
            int a, b, w;
            cin >> a >> b >> w;
            ls.push_back({w,{a,b}});
        }
        sort(all(ls));
        int res = 1;

        for (auto i: ls){
            res *= fastpow(up - i.fi + 1, va[find(i.se.fi)] * va[find(i.se.se)] - 1);
            res %= mod;
            int u = find(i.se.fi);
            int v = find(i.se.se);
            if (u == v){
                continue;
            }
            rt[u] = v;
            va[v] += va[u];
        }

        cout << res << endl;
    }
    return 0;
}