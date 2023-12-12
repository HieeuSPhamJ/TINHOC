#include"bits/stdc++.h"
// #define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 2e5 + 10;
const int inf = 1e9 + 7;

int n, test;
int a[maxN];

multiset <int>  seg[4 * maxN];

void insert(multiset <int> &s, int x){
    s.insert(x);
}

void erase(multiset <int> &s, int x){
    if (s.find(x) != s.end()){
        s.erase(x);
    }
}
void insert(int id, int l, int r, int i, int val){
    if (i < l or r < i){
        return;
    }
    insert(seg[id], val);
    if (l == r){
        return;
    }
    int mid = (l + r) / 2;
    insert(2 * id, l, mid, i, val);
    insert(2 * id + 1, mid + 1, r, i, val);
}

void erase(int id, int l, int r, int i, int val){
    if (i < l or r < i){
        return;
    }
    erase(seg[id], val);
    if (l == r){
        return;
    }
    int mid = (l + r) / 2;
    erase(2 * id, l, mid, i, val);
    erase(2 * id + 1, mid + 1, r, i, val);
}

int get(int id, int l, int r, int L, int R, int lo, int hi){
    if (r < L or R < l){
        return inf;
    }
    if (L <= l and r <= R){
        auto it = seg[id].lower_bound(lo);
        if (it == seg[id].end()){
            return inf;
        }
        if (*it > hi){
            return inf;
        }
        return *it;
    }
    int mid = (l + r) / 2;
    int t1 = get(2 * id, l, mid, L, R, lo, hi);
    int t2 = get(2 * id + 1, mid + 1, r, L, R, lo, hi);
    return min(t1, t2);
}

void insert(int i, int v){
    // cout << "add " << i << " " << v << endl;
    insert(1,1,n,i,v);
}

void erase(int i, int v){
    // cout << "era " << i << " " << v << endl;
    erase(1,1,n,i,v);
}

int get(int l, int r, int lo, int hi){
    return get(1,1,n,l,r, lo, hi);
}


ii mm[maxN];
int res[maxN];
vector <ii> sto[maxN];

struct query{
    int l, r, lo, hi, id;
};

bool cmp(query a, query b){
    return a.l > b.l;
}

int re[maxN];

int find(vector <int> &ts, int x){
    int t = lower_bound(all(ts), x) - ts.begin() + 1;
    re[t] = x;
    return t;
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
    cin >> n >> test;
    // if (n > 1000){
    //     exit(1);
    // }
    vector <int> ts;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        ts.push_back(a[i]);
    }
    vector <query> ask;
    for (int i = 1; i <= test; i++){
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        ask.push_back({l,r,x,y,i});
        ts.push_back(x);
        ts.push_back(y);
    }

    sort(all(ts));

    ts.erase(unique(all(ts)), ts.end());
    int m = ts.size();
    for (int i = 1; i <= n; i++){
        a[i] = find(ts, a[i]);
    }

    for (auto &i: ask){
        i.lo = find(ts, i.lo);
        i.hi = find(ts, i.hi);
    }
    // for (int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    for (int i = 1; i <= m; i++){
        mm[i] = {inf,0};
    }

    for (int i = 1; i <= n; i++){
        mm[a[i]].fi = min(mm[a[i]].fi, i);
        mm[a[i]].se = max(mm[a[i]].se, i);   
    }

    for (int i = 1; i <= m; i++){
        if (mm[i].fi == mm[i].se or mm[i].se == 0){
            continue;
        }
        // cout << mm[i].fi << " " << mm[i].se << endl;
        sto[mm[i].fi].push_back({mm[i].se, i});
    }

    sort(all(ask), cmp);
    priority_queue <ii,vector<ii>,greater<ii>> q;
    for (int i = 1; i <= n; i++){
        for (auto x: sto[i]){
            insert(x.fi, x.se);
            q.push(x);
        }
        while(ask.size() and ask.back().l == i){
            query x = ask.back();
            ask.pop_back();
            res[x.id] = get(x.r,n,x.lo, x.hi);
            // cout << x.r << " " << n << " " << x.lo << " " << x.hi << ": " << res[x.id] << endl;
        }
        while(q.size() and q.top().fi == i){
            ii x = q.top();
            q.pop();
            erase(x.fi, x.se);
        }
    }
    re[0] = -1;
    for (int i = 1; i <= test; i++){
        if (res[i] == inf){
            res[i] = 0;
        }
        cout << re[res[i]] << endl;
    }
    
    return 0;
}