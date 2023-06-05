#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 1e16 + 7;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    n %= mod;
    for (int a = 1; a < k; a++){
        int b = k - a;
        int p = 1;
        for (int i = 1; i <= b; i++){
            p = (p * a) % mod;
        }
        if (p == n){
            cout << a << ' ' << b << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}