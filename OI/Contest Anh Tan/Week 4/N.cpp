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

const int maxN = 1e5 + 10;
const int inf = 1e18;

int n;

bool minimize(int &a, int b){
    if (a > b){
        a = b;
        return 1;
    }
    return 0;
}

struct segmmenttree{
    ii seg[maxN * 4];

    void setlz(int id){
        int v = seg[id].se;
        for (int i = id * 2; i <= id * 2 + 1; i++){
            minimize(seg[i].fi, v);
            minimize(seg[i].se, v);   
        }
    }

    segmmenttree(){
        for (int i = 0; i < 4 * maxN; i++){
            seg[i] = {inf,inf};
        }
    }
    
    void update(int id, int l, int r, int L, int R, int v){
        if (r < L or R < l){
            return;
        }
        if (L <= l and r <= R){
            minimize(seg[id].fi, v);
            minimize(seg[id].se, v);
            return;
        }

        setlz(id);

        int mid = (l + r) / 2;

        update(id * 2, l, mid, L, R, v);
        update(id * 2 + 1, mid + 1, r, L, R, v);
        seg[id].fi = min(seg[id * 2].fi, seg[id * 2 + 1].fi);
    }

    int get(int id, int l, int r, int L, int R){
        if (r < L or R < l){
            return inf;
        }
        if (L <= l and r <= R){
            return seg[id].fi;
        }

        setlz(id);

        int mid = (l + r) / 2;

        return min(get(2 * id, l, mid, L, R), get(2 * id + 1, mid + 1, r, L, R));
    }

    void update(int l, int r, int v){
        l = max(0ll, l);
        if (l > r){
            return;
        }
        if (r == 0){
            return;
        }
        // cout << "up: " << l << " " << r << " " << v << endl;
        update(1,1,maxN,l,r,v);
    }

    int get(int l, int r){
        l = max(0ll, l);
        if (l > r){
            return inf;
        }
        if (r == 0){
            return 0;
        }
        return get(1,1,maxN,l,r);
    }

    void print(){
        for (int i = 0; i <= n; i++){
            if (get(i,i) == inf){
                cout << -1 << " ";
                continue;
            }
            cout << get(i,i) << " ";
        }
        cout << endl;
    }
} Tree;

int a[maxN];
int l[maxN];
int r[maxN];

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
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++){
        l[i] = i;
        l[i] = l[max(1ll, i - a[i] + 1)];
    }
    for (int i = n; i >= 1; i--){
        r[i] = i;
        r[i] = r[min(n, i + a[i] - 1)];
    }

    for (int i = 1; i <= n; i++){
        cout << l[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++){
        cout << r[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++){
        int dp = Tree.get(i,i);
        int dpr = Tree.get(l[i] - 1, i - 1) + 1;
        Tree.update(i,r[i], dpr);
        minimize(dp, dpr);
        // Tree.print();
    }

    cout << Tree.get(n,n) << endl;

    return 0;
}