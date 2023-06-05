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
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> ls;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s >> s >> s;
        int x;
        cin >> x;
        ls.push_back(x);
        // cout << x << endl;
    }
    sort(all(ls));
    pair <int,ii> res = {-1,{-1,-1}};
    for (int i = 1; i < n; i++){
        int del = ls[i] - ls[i - 1];
        if (del <= 1){
            continue;
        }
        if (res.fi < del){
            res.fi = del;
            res.se.fi = ls[i - 1] + 1;
            res.se.se = ls[i] - 1;
        }
    }
    if (res.fi == -1){
        cout << -1 << endl;
    }
    else{
        cout << abs(res.se.fi - res.se.se) + 1 << endl;
        cout << res.se.fi << ' ' << res.se.se << endl;
    }
    return 0;
}