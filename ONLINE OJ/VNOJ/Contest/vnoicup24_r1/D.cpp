#include"bits/stdc++.h"
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 2e5 + 10;

int n;
double a[maxN];

void TRY(double &res){
    for(int t = 1; t <= n * n; t++){
        for(int i = n; i > 1; i--){
            double delta = (a[i] + a[i - 1]) / 2;
            res = res + delta - a[i];
            a[i - 1] = delta;
            a[i] = delta;
        }
    }
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
    int test;
    cin >> test;
    while(test--){
        cin >> n;

        double res = 0;
        int test = 3;
        for (int i = n; i; i--){
            cin >> a[i];
        }
        while(test--){
            TRY(res);
        }

        
        cout << setprecision(8) << fixed << res << endl;
    }
    return 0;
}