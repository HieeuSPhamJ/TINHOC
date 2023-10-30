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

const int maxN = 2e5;
const int inf = 1e18;

int n, test;
ii seg[maxN * 4];
int lazy[maxN * 4];

void setLazy(int i){
    int val = lazy[i];
    lazy[2 * i] += val;
    lazy[2 * i + 1] += val;
    seg[2 * i].fi += val;
    seg[2 * i].se += val;
    seg[2 * i + 1].fi += val;
    seg[2 * i + 1].se += val;
    lazy[i] = 0;
}

void update(int i, int left, int right, int _left, int _right, int val){
    if (right < _left or _right < left){
        return;
    }
    if (_left <= left and right <= _right){
        seg[i].fi += val;
        seg[i].se += val;
        lazy[i] += val;
        return;
    }
    setLazy(i);
    int mid = (left + right) / 2;

    update(2 * i, left, mid, _left, _right, val);
    update(2 * i + 1, mid + 1, right, _left, _right, val);
    seg[i].fi = max(seg[2 * i].fi, seg[2 * i + 1].fi);
    seg[i].se = min(seg[2 * i].se, seg[2 * i + 1].se);
}

ii get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return {-inf,inf};
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }
    setLazy(i);
    int mid = (left + right) / 2;

    ii t1 = get(2 * i, left, mid, _left, _right);
    ii t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return {max(t1.fi,t2.fi), min(t1.se,t2.se)};
}


void update(int l, int r, int v){
    update(1,1,n,l,r,v);
}

ii get(int l, int r){
    return get(1,1,n,l,r);
}

int dp[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("RECIPE.inp", "r")) {
        freopen("RECIPE.inp", "r", stdin);
        freopen("RECIPE.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        update(i,i,x);
    }

    while(test--){
        int l, r, x;
        cin >> l >> r >> x;
        update(l,r,x);
        dp[0] = 0;
        for (int i = 1; i <= n; i++){
            dp[i] = 0;
            for (int j = i - 1; j >= 0;j--){
                ii t = get(j + 1, i);
                dp[i] = max(dp[i], dp[j] + t.fi - t.se);
            }
        }
        cout << dp[n] << endl;
    }


    return 0;
}

/*
1 2 3 4
2 3 3 4
4 3 3 4
*/