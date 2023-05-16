#pragma GCC optimize("O2")
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
const int inf = 1e18;

struct query{
    int id, l, r, k;
};

bool cmp(query a, query b){
    return a.k > b.k;
}

int n, test;

int limitup = 0;
int limitget = 0;

struct segmenttree2d{
    int seg[4 * maxN];
    int re[maxN];
    segmenttree2d(){
        for (int i = 1; i < 4 * maxN; i++){
            seg[i] = -inf;
        }
        for (int i = 1; i < maxN; i++){
            re[i] = -inf;
        }
    }
    void update(int i, int l, int r, int id, int v){
        limitup++;
        if (id < l or r < id){
            return;
        }
        if (l == r){
            seg[i] = v;
            re[id] = v;
            return;
        }

        int mid = (l + r) / 2;

        update(2 * i, l, mid, id, v);
        update(2 * i + 1, mid + 1, r, id, v);

        seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    }
    int get(int i, int l, int r, int L, int R){
        limitget++;
        if (R < l or r < L){
            return -inf;
        }
        if (L <= l and r <= R){
            return seg[i];
        }

        int mid = (l + r) / 2;

        return max(get(2 * i, l, mid, L, R), get(2 * i + 1, mid + 1, r, L, R));
    }
} SEG[4 * maxN];

void update(int i, int down, int up, int x, int y, int val){
    if (x < down or up < x){
        return;
    }
    if (down == up){
        SEG[i].update(1,1,n,y,val);
        return;
    }

    int mid = (down + up) / 2;

    update(2 * i, down, mid, x, y, val);
    update(2 * i + 1, mid + 1, up, x, y, val);

    int vval = SEG[2 * i].re[y];
    vval = max(vval,SEG[2 * i + 1].re[y]);

    // int vval = SEG[2 * i].get(1,1,n,y,y);
    // vval = max(vval,SEG[2 * i + 1].get(1,1,n,y,y));

    SEG[i].update(1,1,n,y,vval);
}

int get(int i, int down, int up, int x, int y, int u, int v){
    if (u < down or up < x){
        return -inf;
    }
    if (x <= down and up <= u){
        // cout << i << " " << x << " " << u << " " << y << " " << v << " " << SEG[i].get(1,1,n,y,v) << endl;
        return SEG[i].get(1,1,n,y,v);
    }

    int mid = (down + up) / 2;

    int t1 = get(2 * i, down, mid, x, y, u, v);
    int t2 = get(2 * i + 1, mid + 1, up, x, y, u, v);
    
    return max(t1,t2);
}

void update(int x, int y, int v){
    update(1, 1, n, x, y, v);
}

int get(int x, int y, int u, int v){
    return get(1, 1, n, x, y, u, v);
}


int a[maxN];
vector <query> ls;
vector <query> sls;
int ans[maxN * maxN];


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> test;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= test; i++){
        int l, r, k;
        cin >> l >> r >> k;
        ls.push_back({i,l,r,k});
    }
    sort(all(ls), cmp);

    for (int i = 1; i <= n; i++){
        for (int j = i, sum = 0; j >= 1; j--){
            sum += a[j];
            sls.push_back({-1,j,i,sum});
        }
    }
    
    sort(all(sls), cmp);

    while(ls.size()){
        query curr = ls.back();
        ls.pop_back();
        while(sls.back().k <= curr.k){
            query seq =  sls.back();
            sls.pop_back();
            // cout << seq.l << " " << seq.r << " " << seq.k << endl;
            update(seq.l, seq.r, seq.k);
        }
        if (n == 1000){
            cout << curr.l << " " << curr.r << ' ' << curr.k << endl; 
        }
        if (limitget + limitup >= 1e8){
            return 0;
        }
        ans[curr.id] = get(curr.l, curr.l, curr.r, curr.r);
    }

    for (int i = 1; i <= test; i++){
        if (ans[i] == -inf){
            cout << "NONE" << endl;
        }
        else{
            cout << ans[i] << endl;
        }
    }


    // update(3, 4, -12);

    // cout << get(4,4,5,5) << endl;

    // cout << limitup << " " << limitget << endl;

    return 0;
}

/*
1 8 -14
2 8 -14
2 4 -14
1 4 -14
3 8 -12
3 4 -12
*/