#include<bits/stdc++.h>
// #define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e3 + 10;

int a[maxN + 1];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("Gapkhuc.inp", "r")) {
        freopen("Gapkhuc.inp", "r", stdin);
        freopen("Gapkhuc.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        int l, r, h;
        cin >> l >> r >> h;
        for (int i = l; i < r; i++){
            a[i] = max(a[i], h);
        }
    }

    int res = 0;

    for (int i = 1,la = 1; i <= maxN; i++){
        // cout << a[i];
        res += abs(a[i] - a[i - 1]);
        if (a[la] != a[i]){
            if (a[la] != 0){
                // cout << la << " " << i << endl;
                res += i - la;
            }
            la = i;
        }
    }
    // cout << endl;

    cout << res << endl;

    int ma = 0;
    int l = -1;
    int r = -1;
    for (int i = 1; i <= maxN; i++){
        if (a[i]){
            if (l == -1){
                l = i;
            }
            r = i;
        }
        ma = max(ma, a[i]);
    }
    // cout << ma << " " << l << " " << r << endl;
    for (int i = ma; i >= 1; i--){
        for (int j = l; j <= r; j++){
            if (i == a[j] or (a[j - 1] <= i and i <= a[j]) or (a[j + 1] <= i and i <= a[j])){
                cout << "#";
            }
            else{
                cout << ".";
            }
        }
        cout << endl;
    }
    for (int j = l; j <= r; j++){
        cout << "*";
    }

    return 0;
}