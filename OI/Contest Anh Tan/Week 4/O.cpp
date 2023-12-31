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

int n;

struct segmmenttree{
    ii seg[maxN * 4];

    void setlz(int id){
        int v = seg[id].se;
        seg[id].se = 0;
        seg[id * 2].fi += v;
        seg[id * 2].se += v;
        seg[id * 2 + 1].fi += v;
        seg[id * 2 + 1].se += v;
    }
    
    void update(int id, int l, int r, int L, int R, int v){
        if (r < L or R < l){
            return;
        }
        if (L <= l and r <= R){
            seg[id].fi += v;
            seg[id].se += v;
            return;
        }

        setlz(id);

        int mid = (l + r) / 2;

        update(id * 2, l, mid, L, R, v);
        update(id * 2 + 1, mid + 1, r, L, R, v);
        seg[id].fi = max(seg[id * 2].fi, seg[id * 2 + 1].fi);
    }

    int get(int id, int l, int r, int L, int R){
        if (r < L or R < l){
            return 0;
        }
        if (L <= l and r <= R){
            return seg[id].fi;
        }

        setlz(id);

        int mid = (l + r) / 2;

        return max(get(2 * id, l, mid, L, R), get(2 * id + 1, mid + 1, r, L, R));
    }

    void update(int l, int r, int v){
        l = max(1ll, l);
        if (l > r){
            return;
        }
        // cout << "up: " << l << " " << r << " " << v << endl;
        update(1,1,maxN,l,r,v);
    }

    int get(int l, int r){
        return get(1,1,maxN,l,r);
    }
} Tree;

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
    int n, m;
    cin >> n >> m;
    n++;
    m++;
    vector <ii> ls;
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++){
        int x, y;
        cin >> x >> y;
        y += 1e5 + 1;
        ls.push_back({x,y});
    }
    sort(all(ls));

    queue <ii> q;
    int res = 0;
    for (auto i: ls){
        while(q.size() and q.front().fi <= i.fi - n){
            Tree.update(q.front().se - m + 1, q.front().se, -1);
            q.pop();
        }
        Tree.update(i.se - m + 1, i.se, 1);
        q.push(i);
        res = max(res, Tree.seg[1].fi);
    }

    cout << res << endl;
    return 0;
}

/*
1 1
1 1
1 2
1 3
2 1
2 2
2 3
3 1
3 2
3 3
4 4
*/