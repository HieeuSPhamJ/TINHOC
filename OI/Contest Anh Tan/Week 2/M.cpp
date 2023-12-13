#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int mod = 1e9 + 7;

bool cmp(ii a, ii b){
    return 1.0 * a.fi / a.se < 1.0 * b.fi / b.se;
}

int add(int a, int b){
    return (a + b) % mod;
}

int mul(int a, int b){
    return (a * b) % mod;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("input.inp", "r")) {
        freopen("input.inp", "r", stdin);
        freopen("A.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <ii> ls;
    vector <ii> ls0;
    vector <ii> goc;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        goc.push_back({a,b});
        if (a * b != 0){
            ls.push_back({a,b});
        }
        else{
            ls0.push_back({a,b});
        }
    }
    sort(all(ls), cmp);
    int cntne = 0;
    int cntpo = 0;
    int res = 0;
    for (auto i: ls){
        res = add(res, mul(cntne, cntpo));
        if (i.se < 0){
            cntne++;
        }
        else{
            cntpo++;
        }
    }
    cout << res << endl;
    return 0;
}