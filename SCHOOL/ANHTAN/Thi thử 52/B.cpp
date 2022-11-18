#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 7;

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, mod;
    cin >> n >> mod;
    int ans = 1;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        for (int j = 1; j < i; j++){
            (ans *= abs(a[i] - a[j])) %= mod;
        }
    }

    cout << ans;


    return 0;
}