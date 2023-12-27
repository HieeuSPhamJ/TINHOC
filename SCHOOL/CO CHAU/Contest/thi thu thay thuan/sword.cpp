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

const int maxN = 1e6 + 10;

vector <ii> ls;
int n;
int ma[maxN];

namespace sub1{
    void solve(){
        int res = 0;
        for (auto i: ls){
            for (auto j: ls){
                if (i != j){
                    if (i.fi <= j.fi and i.se <= j.se){
                        goto bru;
                    }
                }
            }
            res++;
            bru:;
        }
        cout << res << endl;
    }
}

namespace sub2{

    void solve(){      
        for (auto i: ls){
            ma[i.se] = max(ma[i.se], i.fi);
        }
        int res = 0;
        for (int i = n, t = 0; i >= 1; i--){
            if (t < ma[i]){
                res++;
                // cout << ma[i] << " " << i << endl;
            }
            t = max(t, ma[i]);
        }

        cout << res << endl;
    }   
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("sword.inp", "r")) {
        freopen("sword.inp", "r", stdin);
        freopen("sword.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector <int> ts;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        ls.push_back({x,y});
        ts.push_back(x);
        ts.push_back(y);
        
    }

    sort(all(ts));
    ts.erase(unique(all(ts)), ts.end());
    n = ts.size();
    for (auto &i: ls){
        i.fi = lower_bound(all(ts), i.fi) - ts.begin() + 1;
        i.se = lower_bound(all(ts), i.se) - ts.begin() + 1;
    }

    if ((int)ls.size() <= 510){
        sub1::solve();
        return 0;
    }
    sub2::solve();


    return 0;
}