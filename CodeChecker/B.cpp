#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

map <ii,int> cnt;

int d(int x){
    int res = 0;
    for (int i = 1; i * i <= x; i++){
        if (x % i == 0){
            res++;
            if (x / i != i){
                res++;
            }
        }
    }
    return res;
}

ii mini(int x, int y){
    int gcd = __gcd(x,y);
    x /= gcd;
    y /= gcd;
    return {x,y};
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cnt[mini(i, d(i))]++;
        cout << i << ": " << d(i) << endl;
    }
    int res = 0;
    int resdup = 0;
    for (int i = 1; i <= n; i++){
        ii t = mini(k * d(i),  i);
        int x = cnt[t];
        if (k * d(i) * d(i) == i * i){
            x--;
            resdup++;
        }
        res += x;

    }

    cout << res / 2 + resdup << endl;

    return 0;
}