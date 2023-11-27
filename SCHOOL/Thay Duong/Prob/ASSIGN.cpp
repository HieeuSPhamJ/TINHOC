#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 1e9;

map <int,int> cnt[2];
int lon = 1;

int mul(int a, int b){
    return ((a % mod) * (b % mod)) % mod;
}

int fastpow(int n, int a){
    if (a == 0){
        return 1;
    }
    if (a == 1){
        return n;
    }
    int t = fastpow(n, a / 2);
    (t *= t) %= mod;
    if (a % 2){
        t *= n;
    }
    return t % mod;
}

signed main(){
    freopen("ASSIGN.INP", "r", stdin);
    freopen("ASSIGN.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        for (int j = 2; j * j <= x; j++){
            while(x % j == 0){
                cnt[0][j]++;
                x /= j;
            }
        }
        cnt[0][x]++;
    }
    // cout << endl;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        for (int j = 2; j * j <= x; j++){
            while(x % j == 0){
                cnt[1][j]++;
                x /= j;
            }
        }
        cnt[1][x]++;
    }
    vector <ii> ls;
    int res = 1;
    for (auto i: cnt[0]){
        ii t = i;
        t.se = min(t.se,cnt[1][t.fi]);
        // res = mul(res,fastpow(t.fi,t.se));
        ls.push_back(t);
    }
    for (auto i: ls){
        res = mul(res,fastpow(i.fi,i.se));
        while(lon <= 1e9 and i.se){
            lon *= i.fi;
            i.se--;
        }
    }
    if (lon >= 1e9){
        int c = 9;
        int x = res;
        while(x){
            c--;
            x /= 10;
        }
        // cout << c << endl;
        for (int i = 1; i <= c - (res == 0); i++){
            cout << 0;
        }
    }
    cout << res << endl;
    return 0;
}

/*
0000000000
000000000
*/