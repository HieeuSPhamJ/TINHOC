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
    int n;
    cin >> n;
    vector <int> ls;
    int res = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        ls.push_back(x);
        res = res xor x;
    }
    if (res != 0){
        cout << -1 << endl; 
        return 0;
    }
    int cnt = 0;
    for (int k = *max_element(all(ls)); k >= 1; k--){
        res = 0;

        for (auto i: ls){
            res = res xor (i % (k + 1));
            cnt++;
        }
        if (res != 0){
            cout << k << endl; 
            return 0;
        }
        if (cnt >= 1e8){
            break;
        }
    }

    cout << 0 << endl;
    return 0;
}