#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 3e5 + 10;
const int mod = 1e9 + 7;
int n;

struct segmenttree{
    int seg[maxN * 4];
    int lazy[maxN * 4];
    segmenttree(){
        memset(lazy, 0, sizeof(lazy));
        memset(seg, 0, sizeof(seg));
        
    }
    void setLazy(int i, int l, int r){
        int val = lazy[i];
        lazy[i] = 0;
        if (val == 0){
            return;
        }
        int mid = (l + r) / 2;
        seg[2 * i] += val * (mid - l + 1);
        seg[2 * i + 1] += val * (r - mid);
        lazy[2 * i] += val;
        lazy[2 * i + 1] += val;
    }

    void update(int i, int left, int right, int _left, int _right, int val){
        if (right < _left or _right < left){
            return;
        }
        if (_left <= left and right <= _right){
            seg[i] += (right - left + 1) * val;
            lazy[i] += val;
            return;
        }

        setLazy(i, left, right);

        int mid = (left + right) / 2;

        update(2 * i, left, mid, _left, _right, val);
        update(2 * i + 1, mid + 1, right, _left, _right, val);
        seg[i] = (seg[2 * i] + seg[2 * i + 1]);
    }

    int get(int i, int left, int right, int _left, int _right){
        if (right < _left or _right < left){
            return 0;
        }
        if (_left <= left and right <= _right){
            return seg[i];
        }

        setLazy(i, left, right);

        int mid = (left + right) / 2;

        int t1 = get(2 * i, left, mid, _left, _right);
        int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
        return t1 + t2;
    }

    void update(int l, int r, int v){
        // cout << "+ " << l << " " << r << endl;
        update(1,1,n,l,r,v);
    }

    int get(int l, int r){
        return get(1,1,n,l,r);
    }

} Tree;

int la[maxN];

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
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        Tree.update(la[x] + 1, i, 1);
        (res += Tree.get(1,n)) %= mod;
        la[x] = i;
    }
    cout << res << endl;
    return 0;
}