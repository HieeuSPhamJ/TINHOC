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
int l[maxN];
int r[maxN];

signed main(){
    freopen("kagain.INP", "r", stdin);
    freopen("kagain.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] == 0){
            cout << "123123" << endl;
            exit(1);
        }
    }
    a[0] = -1e18;
    a[n + 1] = -1e18;
    for (int i = 1; i <= n; i++){
        int t = i;
        while(a[t - 1] >= a[i]){
            t = l[t - 1];
        }
        l[i] = t;
    }
    r[n + 1] = n + 1;
    for (int i = n; i >= 1; i--){
        int t = i;
        while(a[t + 1] >= a[i]){
            t = r[t + 1];
        }
        r[i] = t;
    }
    
    int res = -1e18;
    ii d = {-1,-1};
    for (int i = 1; i <= n; i++){
        // cout << (r[i] - l[i] + 1) << endl;
        int t = a[i] * (r[i] - l[i] + 1);
        if (t > res){
            res = t;
            d = {l[i], r[i]};
        }
        if (t == res){
            if (d.fi > l[i]){
                d = {l[i], r[i]};
            }
        }
    }
    cout << res << " " << d.fi << " " << d.se << endl;
    return 0;
}