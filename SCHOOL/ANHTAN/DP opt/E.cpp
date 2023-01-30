#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e3 + 10;

int n, m;
int a[maxN][maxN];
int b[maxN];
int L[maxN];
int R[maxN];

ii seg[maxN * 4];

ii com(ii x, ii y){
    x.fi = max(x.fi,y.fi);
    x.se = min(x.se,y.se);
    return x;
}

void update(int i, int left, int right, int index, ii val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i] = val;
        return;
    }
    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);
    seg[i] = com(seg[2 * i], seg[2 * i + 1]);
}

ii get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return {0,1e18};
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    ii t1 = get(2 * i, left, mid, _left, _right);
    ii t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return com(t1, t2);
}

void reset(){
    for (int i = 0; i < 4 * maxN; i++){
        seg[i].fi = 0;
        seg[i].se = 1e18;
    }
}

ii ge(int l, int r){
    return get(1,1,n,l,r);
}

void up(int t, int i, int v){
    ii g = ge(i,i);
    if (t == 0){
        g.fi = v;
    }
    else{
        g.se = v;
    }
    update(1,1,n,i,g);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i][j] == 0){
                b[j] = 0;
            }
            else{
                b[j]++;
            }
        }
        reset();
        for (int i = 1; i <= m; i++){
            update();
            L[i] = ge(b[i], n).se;
        }
    }
    return 0;
}