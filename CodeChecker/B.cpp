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

const int maxN = 100;

int a[maxN];

vector <int> ls;

int sto[maxN];
int res;

void backtrack(int id, int ma = 0){
    if (id >= ls.size()){
        if (ma >= res){
            return;
        }
        map<int,vector <int>> s;
        for (int i = 0; i < ls.size(); i++){
            s[sto[i]].push_back(ls[i]);
        }
        int ok = 1;
        // cout << "----" << endl;
        for (auto ss: s){
            for (int ix = 0; ix < (int)ss.se.size(); ix++){
                for (int iy = ix + 1; iy < (int)ss.se.size(); iy++){
                    int c = ss.se[ix] * ss.se[iy];
                    // cout << c << "|" << sqrtl(c) << " ";
                    if (c < 0){
                        ok = 0;
                    }
                    if ((int)sqrtl(c) * (int)sqrtl(c) == c){
                        continue;
                    }
                    ok = 0;
                }
            }
            // cout << endl;
        }
        if (ok == 0){
            return;
        }
        // cout << "With:" << endl;
        // for (auto ss: s){
        //     for (auto x: ss.se){
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }
        res = min(res, ma);
        return;
    }
    for (int i = 1; i <= ma + 1; i++){
        sto[id] = i;    
        backtrack(id + 1, max(ma, i));
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("input.inp", "r")) {
        freopen("input.inp", "r", stdin);
        freopen("B.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    while(test--){
        int l, r;
        cin >> l >> r;
        ls.clear();
        res = 1e18;
        for (int i = l; i <= r; i++){
            ls.push_back(a[i]);
        }
        backtrack(0,0);
        cout << res << endl;
    }
    return 0;
}