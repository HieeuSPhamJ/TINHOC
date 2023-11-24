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
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        set <int> s;
        for (int i = 1; i <= n; i++){
            int x = 1e9 / i;
            s.insert(x);
        }
        vector <int> res;
        while(s.size() > 1){
            if (*s.rbegin() % 2 == 0 and *s.begin() % 2 == 1){
                res.push_back(1);
            }
            else{
                res.push_back(0);
            }
            set <int> ts;
            for (auto i: s){
                ts.insert((i + res.back()) / 2);
            }
            swap(ts,s);
        }
        cout << res.size() << endl;
        if (res.size() <= n){
            for (auto i: res){
                cout << i << " ";
            }
            if (res.size()){
                cout << endl;
            }
        }
    }
    return 0;
}
/*
*/