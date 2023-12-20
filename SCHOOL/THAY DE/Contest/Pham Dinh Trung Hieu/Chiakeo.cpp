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

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("Chiakeo.inp", "r")) {
        freopen("Chiakeo.inp", "r", stdin);
        freopen("Chiakeo.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> k >> n;
    vector <int> ls;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        ls.push_back(x);
        sum += x;
    }
    sort(all(ls));
    int l = 0;
    int r = 1e9;
    int tm = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        int cost = 0;
        for (auto i: ls){
            if (i > m){
                cost += i - m;
            }
            if (cost > k){
                break;
            }
        }
        if (cost > k){
            l = m + 1;
            tm = m + 1;
        }
        else{
            r = m - 1;
        }
    }

    for (auto &i: ls){
        if (i > tm) {
            k -= (i - tm);
            i = tm;
        }
    }
    reverse(all(ls));
    int res = 0;
    for (auto &i: ls){
        if (k > 0){
            k--;
            i--;
        }
        res += i * i;
    }


    cout << res << endl;
    return 0;
}