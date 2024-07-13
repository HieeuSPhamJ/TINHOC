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
    if (fopen("REMOVE.inp", "r")) {
        freopen("REMOVE.inp", "r", stdin);
        freopen("REMOVE.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int res = 1;
    while(n % k){
        cout << n % k << endl;
        res++;
        n -= n / k + 1;
    }
    cout << res << endl;
    return 0;
}

/*

*/