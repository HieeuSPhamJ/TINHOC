#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

int a[maxN];
double pre[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1];
        pre[i] += min(a[i], a[i - 1]) + 1.0 * (a[i] - a[i - 1]) / 2;
    }

    while(test--){
        int l, r;
        cin >> l >> r;
        cout << fixed << setprecision(1) << pre[r] - pre[l] << endl;
    }

    return 0;
}