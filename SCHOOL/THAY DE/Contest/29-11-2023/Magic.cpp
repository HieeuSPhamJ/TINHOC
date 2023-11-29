#include"bits/stdc++.h"
// #define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 5e5 + 10;

int n;

int a[maxN];
int mil[maxN];
int mir[maxN];
int mal[maxN];
int mar[maxN];

void init(){
    for (int i = 1; i <= n; i++){
        int t = i;
        while(t > 1 and a[t - 1] >= a[i]){
            t = mil[t - 1];
        }
        mil[i] = t;
        i = i;
        while(t > 1 and a[t - 1] <= a[i]){
            t = mal[t - 1];
        }
        mal[i] = t;
    }
    for (int i = n; i >= 1; i--){
        int t = i;
        int cnt = n;
        while(t < n and a[t + 1] >= a[i]){
            t = mir[t + 1];
        }
        mir[i] = t;
        t = i;
        cnt = n;
        while(t < n and a[t + 1] <= a[i]){
            t = mar[t + 1]; 
        }
        mar[i] = t;
    }
}


int solve(int l, int r){
    int res = 0;
    // cout << "With: " << l << " " << r << endl;
    for (int i = l; i <= r; i++){
        for (int j = i, ma = a[i], mi = a[i]; j <= r and j <= max(mir[j], mar[j]); j++){
            ma = max(ma, a[j]);
            mi = min(mi, a[j]);
            if ((ma == a[i] and mi == a[j]) or (ma == a[j] and mi == a[i])){
                res = max(res, j - i + 1);
                // cout << i << " " << j << endl;
            }
            if (res == r - i + 1){
                return res;
            }
        }
    }
    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("Magic.inp", "r")) {
        freopen("Magic.inp", "r", stdin);
        freopen("Magic.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    init();

    int test;
    cin >> test;
    while(test--){
        int l, r;
        cin >> l >> r;
        cout << solve(l,r) << endl;
    }
    return 0;
}