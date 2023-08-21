#include<bits/stdc++.h>
#define ii pair <int,int>
#define iii pair <ii, int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    // freopen("input.inp", "r", stdin);
    // freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    vector <iii> ls;
    while(test--){
        int t;
        cin >> t;
        if (t == 1){
            int l, r, x;
            cin >> l >> r >> x;
            ls.push_back({{l,r},x});
        }
        else{
            int res = 0;
            int l, r;
            cin >> l >> r;
            // cout << "===ANS===" << endl;
            for (auto i: ls){
                int L = i.fi.fi;
                int R = i.fi.se;
                L = max(l, L);
                R = min(r, R);
                if (L < R){
                    int v = i.se;
                    if ((R - L + 1) % 2){
                        res = res xor v;
                    }
                }
            }
            cout << res << endl;
            ls.clear();
        }
    }
    return 0;
}