#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 5e5 + 10;
const int inf = 2e18;

int n, m;
ii a[maxN];
ii b[maxN];
int dp[maxN];
int bit[maxN];

struct segmenttree{
    int seg[4 * maxN];
    void update(int i, int left, int right, int index, int val){
        if (index < left or right < index){
            return;
        }
        if (left == right){
            seg[i] = max(seg[i],val);
            return;
        }
        int mid = (left + right) / 2;

        update(2 * i, left, mid, index, val);
        update(2 * i + 1, mid + 1, right, index, val);
        seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    }

    int get(int i, int left, int right, int _left, int _right){
        if (right < _left or _right < left){
            return -inf;
        }
        if (_left <= left and right <= _right){
            return seg[i];
        }

        int mid = (left + right) / 2;

        int t1 = get(2 * i, left, mid, _left, _right);
        int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
        return max(t1, t2);
    }

    void update(int i, int v){
        update(1,1,m,i,v);
    }
    int get(int l, int r){
        return get(1,1,m,l,r);
    }
} Tree;

struct Fenwick{
    int bit[maxN];
    
    void update(int i, int v){
        while(i <= m){
            bit[i] = max(bit[i], v);
            i += i & (-i);
        }
    }
    int get(int i){
        int res = 0;
        while(i){
            res = max(res, bit[i]);
            i -= i & (-i);
        }
        return res;
    }
} Bit;

void nenso(){
    set <int> s;
    for (int i = 1; i <= n; i++){
        s.insert(a[i].fi);
        s.insert(a[i].se);   
    }
    map <int,int> cv;
    for (auto i: s){
        m++;
        cv[i] = m;
    }
    for (int i = 1; i <= n; i++){
        b[i].fi = cv[a[i].fi];
        b[i].se = cv[a[i].se];
        
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 1; i < 4 * maxN; i++){
        Tree.seg[i] = -inf;
    }
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        a[i].fi = x;
        a[i].se = x + y;
    }
    nenso();
    // for (int i = 1; i <= n; i++){
    //     cout << a[i].fi << " " << a[i].se << endl;
    // }
    for (int i = 1; i <= n; i++){
        a[i].se -= a[i].fi;
    }
    int res = -inf;
    for (int i = 1; i <= n; i++){
        int &cur = dp[i] = a[i].se;
        int s = a[i].fi + a[i].se;
        // for (int i = 1; i <= n; i++){
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        cur = max(cur, Bit.get(b[i].fi - 1) + a[i].se);
        cur = max(cur, Tree.get(b[i].fi, b[i].se) + s);
        Bit.update(b[i].se, cur);
        Tree.update(b[i].se, cur - s);
        res = max(res, cur);
    }
    cout << res << endl;
    

    return 0;
}