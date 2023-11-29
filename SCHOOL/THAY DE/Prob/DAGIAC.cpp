#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

signed main(){
    freopen("DAGIAC.INP", "r", stdin);
    freopen("DAGIAC.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << n * (n - 1) * (n - 2) * (n - 3) / 24;
    return 0;
}