#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    freopen("YEAR.INP", "r", stdin);
    freopen("YEAR.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> ls;
    for (int i = 1, la = 1000; i <= n; i++){
        int x;
        cin >> x;
        int res = 1e18;
        for (int p = 0, t = 1; p <= 3; p++){
            int tx = x - (x % (t * 10)) / t * t;
            // cout << tx << endl;
            for (int j = 0; j <= 9; j++){
                // cout << tx << endl;
                if (1000 <= tx and tx <= 2011){
                    if (la <= tx){
                        res = min(res,tx);
                    }
                } 
                tx += t;
            }
            t *= 10;
        }
        if (res != 1e18){
            la = res;
            ls.push_back(res);
        }
        else{
            cout << -1 << endl;
            goto bru;
        }
    }
    for (auto i: ls){
        cout << i << endl;
    }
    bru:;

    return 0;
}