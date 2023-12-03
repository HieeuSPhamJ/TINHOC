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

int cal(vector <int> ls){
    int res = 100;
    if (ls.empty()){
        return 0;
    }
    int n = ls.size() - 1;
    for (int i = 0, la = 0; i <= n; i++){
        if (i == n or ls[la] != ls[i + 1]){
            vector <int> ts;
            for (int j = 0; j <= n; j++){
                if (j < la or i < j){
                    ts.push_back(ls[j]);
                    // cout << " add: " << j << endl;
                }
            }
            la = i + 1;
            int tres = cal(ts) + 1;
            // cout << "from ";
            // for (auto x: ls){
            //     cout << x;
            // }
            // cout << endl;
            // cout << "to ";
            // for (auto x: ts){
            //     cout << x;
            // }
            // cout << endl;
            // cout << "era:" << la << " " << i << endl;
            // cout << tres << endl;
            res = min(res,tres);

        }
    }
    // for (auto i: ls){
    //     cout << i;
    // }
    // cout << ": " << res << endl;
    return res;
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
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
    vector <int> ls;
    for (int i = 1; i <= n; i++){
        char x;
        cin >> x;
        ls.push_back(x - 'a');
    }
    cout << cal(ls) << endl;
    return 0;
}