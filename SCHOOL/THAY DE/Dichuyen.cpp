#include<bits/stdc++.h>
#define int long long
// #define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

struct car{
    double i;
    int c;
    char d;
} cars[maxN];
double res[maxN];
int c[45];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("Dichuyen.inp", "r")) {
        freopen("Dichuyen.inp", "r", stdin);
        freopen("Dichuyen.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, l;
    cin >> n >> k >> l;
    for (int i = 1; i <= n; i++){
        cin >> cars[i].i >> cars[i].c >> cars[i].d;
        if (cars[i].d == 'D'){
            res[cars[i].c] += l - cars[i].i;
            // cout << cars[i].c << " " << l - cars[i].i << endl;
        }
    }
    for (int i = 1; i <= n; i++){
        if (cars[i].d == 'L'){
            car cur = cars[i];
            double t = cars[i].i;
            // cout << "with: " << i << endl;
            for (int j = i - 1; j >= 1; j--){
                if (cars[j].d == 'D'){
                    double no = (cur.i + cars[j].i) / 2;
                    // cout << cur.c << " " << cars[j].i << ": " << t << " " << no << " " << t - no << endl;
                    res[cur.c] += t - no;
                    (cur.c += cars[j].c) %= k;
                    t = no;
                }
            }
            // cout << cur.c << " " << t << endl;
            res[cur.c] += t;
        }
    }
    // cout << "=====" << endl;

    for (int i = 0; i < k; i++){
        cout << fixed << setprecision(1) << res[i] << endl;
    }
    return 0;
}

/*
0 0.5 1 1.5 2 2.5 3 3.5 4 4.5 5
      *           *     *     *

0 0.5
2 2
3
*/