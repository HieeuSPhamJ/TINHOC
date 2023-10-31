#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e6 + 10;

int f(ii y, int x){
    return y.fi * x + y.se;
}

ii seg[maxN * 4];

void update(int id, int l, int r, ii nf){
    int m = (l + r) / 2;
    bool mid = f(seg[id], m) > f(nf,m);
    bool left = f(seg[id], l) > f(nf,l);
    if (mid){
        swap(seg[id], nf);
    }
    if (r - l == 1){
        return;
    }
    if (left != mid){
        update(2 * id, l, m, nf);
    }
    else{
        update(2 * id + 1, m, r, nf);
    }
}

int get(int id, int l, int r, int x){
    int m = (l + r) / 2;
    int cur = f(seg[id], x);
    if (r - l == 1){
        return cur;
    }
    if (x < m){
        return min(cur, get(2 * id, l, m, x));
    }
    return min(cur, get(2 * id + 1, m, r, x));
}

int dp[maxN];
int pre[maxN];
int w[maxN];
int h[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("BRIDGEPOL.inp", "r")) {
        freopen("BRIDGEPOL.inp", "r", stdin);
        freopen("BRIDGEPOL.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 1; i < 4 * maxN; i++){
        seg[i] = {0,1e18};
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> w[i];
        dp[i] = 1e18;
        pre[i] = pre[i - 1] + w[i];
    }
    dp[1] = 0;
    update(1,0,maxN, {-2 * h[1], h[1] * h[1] - pre[1] + dp[1]});
    for (int i = 2; i <= n; i++){
        int co = h[i] * h[i] + pre[i - 1];
        dp[i] = get(1,0,maxN,h[i]) + co;
        update(1,0,maxN, {-2 * h[i], h[i] * h[i] - pre[i] + dp[i]});
    }
    cout << dp[n] << endl;
    
    return 0;
}

/*
dp[i] = - 2 * h[i] * h[j] + 
a = -2 * h[j]
b = h[j] * h[j] - pre[j] + dp[j] 

*/