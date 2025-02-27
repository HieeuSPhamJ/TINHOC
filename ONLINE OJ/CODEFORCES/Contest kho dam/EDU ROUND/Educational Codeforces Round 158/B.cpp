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
        vector <int> ls;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            ls.push_back(x);
        }
        int la = 1;
        int res = 0;
        for (auto i: ls){
            if(la < i){
                res += (i - la);
            }
            la = i;
        }
        cout << res << endl;
    }
    return 0;
}