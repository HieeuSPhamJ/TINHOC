#include"bits/stdc++.h"
// #include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int n, k;
double a[maxN];
double pre[maxN];

bool check(double v){
    pre[0] = 0;
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + (a[i] - v);
    }
    set <double> s;

    // for (int i = 0; i <= n; i++){
    //     cout << pre[i] << " ";
    // }
    // cout << endl;

    for (int i = k; i <= n; i++){
        if (i - k >= 0){
            s.insert(pre[i - k]);
        }
        auto it = s.upper_bound(pre[i]);
        if (it != s.begin()){
            it--;
            // cout << i << " " << *it << endl;
            return 1;
        }
    }

    return 0;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    double res = 0;
    double l = -1e6;
    double r = 1e6;
    while(r - l >= 2e-6){
        double mid = (l + r) / 2;
        if (check(mid)){
            l = mid;
            res = mid;
        }
        else{
            r = mid;
        }
    }

    // cout << check(3.6) << endl;

    cout << fixed << setprecision(5) << res << endl;
    return 0;
}