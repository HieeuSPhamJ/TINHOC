#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5e5 + 10;

int a[maxN];
int dpl[maxN];
int dpr[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        dpl[i] = 1;
        dpl[i] = min(dpl[i - 1] + 1, a[i]);
    }
    int res = 0;
    for (int i = n; i >= 1; i--){
        dpr[i] = 1;
        dpr[i] = min(dpr[i + 1] + 1, a[i]);
        res = max({res,min(dpl[i], dpr[i])});
    }
    // for (int i = 1; i <= n; i++){
    //     cout << dpl[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++){
    //     cout << dpr[i] << " ";
    // }
    // cout << endl;
    cout << res << endl;
    return 0;
}