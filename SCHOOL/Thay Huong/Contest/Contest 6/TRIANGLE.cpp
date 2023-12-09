#include"bits/stdc++.h"
// #define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int a, b, c;
long long s, t;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("TRIANGLE.inp", "r")) {
        freopen("TRIANGLE.inp", "r", stdin);
        freopen("TRIANGLE.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int sum;
    cin >> sum;
    if (sum % 2){
        cout << 0 << endl;
        return 0;
    }
    int p = sum / 2;
    // int ga = p / 3;
    int res = 0;
    for(a = 2; a < p; a += 2){
        b = max(a, p - a + 1);
        b += b % 2;
        c = sum - a - b;
        while (b < p and b <= c and b - a < c){
            s = 1ll * p * (p - a) * (p - b) * (p - c);
            // cout << a << " " << b << " " << c << endl;
            t = sqrt(s);
            if (t * t != s){

            }
            else if (t % p){

            }
            else if ((1ll * a * b * c) % (4ll * t) == 0){
                res++;
            }
            b += 2;
            c -= 2;
        }
    }
    cout << res << endl;
    return 0;
}