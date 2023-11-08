#include<bits/stdc++.h>
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
    if (fopen("cc.inp", "r")) {
        freopen("cc.inp", "r", stdin);
        freopen("cc.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> deg(n + 1);
    int ma = 0;
    for (int i = 1; i <= 2 * (n - 1); i++){
        int x;
        cin >> x;
        deg[x]++;
        ma = max(ma, deg[x]);
    }

    cout << ma << endl;

    return 0;
}