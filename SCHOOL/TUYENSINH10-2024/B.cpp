#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e6 + 10;

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("bai2.inp", "r")) {
        freopen("bai2.inp", "r", stdin);
        freopen("bai2.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        char x;
        cin >> x;
        if (x == 'A'){
            a[i] = 1;
        }
        else if (x == 'B'){
            a[i] = 2;
        }
    }

    int res_a = 0;
    int res_b = 0;

    for (int i = 1; i < n; i++){
        if (a[i] == 1 and a[i + 1] == 1){
            res_a++;
        }
        else if ((a[i] == 1 or a[i + 1] == 1) and a[i] * a[i + 1] == 0){
            res_a++;
        }
        else if (a[i] == 0 and a[i + 1] == 0){
            res_a++;
        }

        if (a[i] == 2 and a[i + 1] == 2){
            res_b++;
        }
        else if ((a[i] == 2 or a[i + 1] == 2) and a[i] * a[i + 1] == 0){
            res_b++;
        }
        else if (a[i] == 0 and a[i + 1] == 0){
            res_b++;
        }
    }

    cout << max(res_a, res_b);

    return 0;
}