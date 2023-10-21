#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5010;
const int mod = 1e9 + 7;

int a[maxN][maxN];
int duoi[maxN];
int tren[maxN];
int pre[maxN];

signed main(){
    freopen("GRFLRS.INP", "r", stdin);
    freopen("GRFLRS.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, t1, t2;
    cin >> n >> m >> t1 >> t2;
    for (int i = 1; i <= n; i++){
        duoi[i] = 1e18;
        tren[i] = 0;
    }

    while(t1--){
        int x, y;
        cin >> x >> y;
        duoi[x] = min(duoi[x], y);
    }
    while(t2--){
        int x, y;
        cin >> x >> y;
        tren[x] = max(tren[x], y);
    }

    for (int i = 2; i <= n; i++){
        duoi[i] = min(duoi[i], duoi[i - 1]);
    }
    for (int i = n - 1; i >= 1; i--){
        tren[i] = max(tren[i], tren[i + 1]);
    }
    
    for (int i = 1; i <= n; i++){
        // cout << duoi[i] << " " << tren[i] << endl;
        if (duoi[i] <= tren[i]){
            pre[duoi[i]]++;
            pre[tren[i] + 1]--;
        }
    }

    for (int i = 1; i <= m; i++){
        pre[i] += pre[i - 1];
    }

    int res = 0;

    for (int r = 1; r <= m; r++){
        for (int l = r, t = 1e18; l >= 1; l--){
            t = min(t, pre[l]);
            res += t * (t - 1) / 2 + t;
            res %= mod;
            // cout << l << " " << r << " " << t << endl;
        }
    }

    cout << res << endl;
    return 0;
}