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

const int maxN = 2e5 + 10;

int n, test;
int a[maxN];

namespace sub1{
    int bit[2][maxN];

    void update(int t, int id, int v){
        if (t == 1){
            id = n - id + 1;
        }
        for (;id <= n; id += id & -id){
            bit[t][id] = max(bit[t][id], v);
        }
    }

    int get(int t, int id){
        if (t == 1){
            id = n - id + 1;
        }
        int res = 0;
        for (;id; id -= id & -id){
            res = max(res, bit[t][id]);
        }
        return res;
    }

    void solve(){
        while(test--){
            int l, r;
            cin >> l >> r;
            for (int i = 1; i <= n; i++){
                bit[0][i] = bit[1][i] = 0;
            }
            for (int i = l; i <= r; i++){
                update(0,a[i],get(1,a[i] + 1) + 1);
                if (get(0,a[i] - 1)){
                    update(1,a[i],get(0,a[i] - 1) + 1);
                }
            }
            cout << get(0,n) << endl;
        }
    }

}

namespace sub2{
    struct node{
        int d[2][2];
        node(){
            memset(d, 0, sizeof(d));
        }
    } seg[maxN * 4];

    node merge(node &b, node &c){
        node a;
        for (int st = 0; st <= 1; st++){
            for (int en = 0; en <= 1; en++){
                int &t = a.d[st][en];
                t = max(b.d[st][en], c.d[st][en]);
                if (b.d[st][0] * c.d[1][en]){
                    t = max(t, b.d[st][0] + c.d[1][en]);
                }
                if (b.d[st][1] * c.d[0][en]){
                    t = max(t, b.d[st][1] + c.d[0][en]);
                }
            }
        }
        return a;
    }

    void print(node &t){
        cout << t.d[0][0] << " " << t.d[1][1] << " " << t.d[0][1] << " " << t.d[1][0] << endl;
    }

    void build(int id, int l, int r){
        if (l > r){
            return;
        }
        if (l == r){
            if (a[l] == 1){
                seg[id].d[0][0] = 1;
            }
            else{
                seg[id].d[1][1] = 1;
            }
            // cout << l << " " << r << ": " << endl;
            // print(seg[id]);
            return;
        }

        int mid = (l + r) / 2;

        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);

        seg[id] = merge(seg[2 * id], seg[2 * id + 1]);
        // cout << l << " " << r << ": " << endl;
        // print(seg[id]);
    }

    node get(int id, int l, int r, int L, int R){
        if (r < L or R < l){
            return node();
        }
        if (L <= l and r <= R){
            return seg[id];
        }

        int mid = (l + r) / 2;
        node t1 = get(2 * id, l, mid, L, R);
        node t2 = get(2 * id + 1, mid + 1, r, L, R);
        return merge(t1, t2);
    }

    int get(int l, int r){
        node t = get(1,1,n,l,r);
        // print(t);
        if (!t.d[0][0] and !t.d[0][1] and !t.d[1][0]){
            return t.d[1][1];
        }
        return t.d[0][0];
    }    

    void solve(){
        build(1,1,n);
        while(test--){
            int l, r;
            cin >> l >> r;
            cout << get(l,r) << endl;
        }
    }
}

signed main(){
    if (fopen("input.inp", "r")) {
        freopen("input.inp", "r", stdin);
        freopen("B.out", "w", stdout);
    }
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("CLIMBING.inp", "r")) {
        freopen("CLIMBING.inp", "r", stdin);
        freopen("CLIMBING.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> test;
    vector <int> ts;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        ts.push_back(a[i]);
    }
    sort(all(ts));
    ts.erase(unique(all(ts)), ts.end());
    for (int i = 1; i <= n; i++){
        a[i] = lower_bound(all(ts), a[i]) - ts.begin() + 1;
        // cout << a[i] << ' ';
    }
    if (n * test <= 1e7){
        sub1::solve();
        return 0;
    }
    sub2::solve();
    return 0;
}