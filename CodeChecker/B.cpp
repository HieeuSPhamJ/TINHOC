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
    string s = " ";
    for (int i = 1; i <= 5000; i++){
        s = s + to_string(i);
        // if (s.size() > 10000){
        //     cout << i - 1 << endl;
        //     break;
        // } 
    }
    // cout << s.size() << endl;
    int test;
    cin >> test;
    while(test--){
        int x;
        cin >> x;
        cout << s[x] << endl;
    }
    return 0;
}

/*
*/