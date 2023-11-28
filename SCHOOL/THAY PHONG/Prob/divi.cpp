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

unordered_map <int,int> cnt;
int d[maxN];
void init(){
    for (int i = 1; i < maxN; i++){
        for (int j = i; j < maxN; j += i){
            d[j] += 1;
        }
    }
}

ii mini(int x, int y){
    int gcd = __gcd(x,y);
    x /= gcd;
    y /= gcd;
    return {x,y};
}

int conv(ii x){
    return (int)(x.fi * 1e9 + x.se) % (int)(1e9 + 7);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    init();
    for (int i = 1; i <= n; i++){
        cnt[conv(mini(i, d[i]))]++;
        // cout << i << ": " << d[i] << endl;
    }
    int res = 0;
    int resdup = 0;
    for (int i = 1; i <= n; i++){
        ii t = mini(k * d[i],  i);
        int x = cnt[conv(t)];
        if (k * d[i] * d[i] == i * i){
            x--;
            resdup++;
        }
        res += x;

    }

    cout << res / 2 + resdup << endl;

    return 0;
}