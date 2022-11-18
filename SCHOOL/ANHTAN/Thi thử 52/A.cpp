#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int f[60];
    f[0] = 3;
    f[1] = 3;
    for (int i = 2; i <= 55; i++){
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n];
    return 0;
}