#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;

int On(int n){
    int res = n;
    for (int i = 1; i <= n - 1; i++)
        res = (res + (n-1)/i * (n+(n-1)%i-i+1) / 2) % mod;
    return res;
}

signed main(){
    freopen("NUMCITIES.inp", "r", stdin);
    freopen("NUMCITIES.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while (test--){
        int n;
        cin >> n;
        cout << On(n + 1) << endl;
    }
    
    return 0;
}