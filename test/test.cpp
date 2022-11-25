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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int f[1000];
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= 1000; i++){
        f[i] = (f[i - 1] + f[i - 2]);
    }
    for (int i = 1; i <= 13; i++){
        cout << f[i] << " ";
    }
    cout << endl;
    return 0;       
}