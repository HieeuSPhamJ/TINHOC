#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3e5 + 10;

map <ii,int> a;
map <ii,ii> sto;
int ALLRES = 0;
int n, test;
set <ii> s;
vector <ii> seg[4 * maxN];
int lastx[maxN];
int lasty[maxN];

struct dsulmao{
    int root[maxN];
    int sz[maxN];
    vector <ii> st;

    void init(){
        for (int i = 1; i < maxN; i++){
            root[i] = 0;
            sz[i] = 0;
        }
    }

    int find(int nu){
        if (nu == root[nu]){
            return nu;
        }
        st.push_back({nu,root[nu]});
        return root[nu] = find(root[nu]);
    }

    void add(ii e){
        // cout << "+ add " << e.fi << ' ' << e.se << endl;
        st.push_back({0,0});
        int u = find(e.fi);
        int v = find(e.se);
        if (u == v){
            return;
        }
        st.push_back({u,root[u]});
        root[u] = v;
        sz[v] += sz[u];
        st.push_back({-v,-u});
    }
    void del(ii e){
        // cout << "- del "<< endl;
        while(st.back().fi != 0){
            // cout << st.back().fi << ' ' << st.back().se << endl;
            if (st.back().fi < 0){
                int v = -st.back().fi;
                int u = -st.back().se;
                sz[v] -= sz[u];
            }
            else{
                root[st.back().fi] = st.back().se;
            }
            st.pop_back();
        }
        st.pop_back();
    }

};

dsulmao DSUx;
dsulmao DSUy;

void update(int i, int l, int r, int L, int R, ii v){
    if (r < L or R < l){
        return;
    }
    if (L <= l and r <= R){
        seg[i].push_back(v);
        return;
    }
    int mid = (l + r) / 2;
    update(2 * i,l,mid,L,R,v);
    update(2 * i + 1,mid + 1,r,L,R,v);
}

void walk(int i, int l, int r){
    for (auto x: seg[i]){
        if (s.find(x) == s.end()){
            s.insert(x);
            if (lastx[x.fi] != 0){
                DSUx.add({x.fi, lastx[x.fi]});
            }
            
            if (lasty[x.se] != 0){
                DSUy.add({x.fi, lasty[x.se]});
            }
            lastx[x.fi] = x.se;
            lasty[x.se] = x.fi;
            sto[x] = {lastx[x.fi], lasty[x.se]};

        }
    }

    if (l == r){
        cout << ALLRES << " ";
        for (auto x: seg[i]){
            if (s.find(x) != s.end()){
                s.erase(s.find(x));
                DSUx.del({x.fi,sto[x].fi});
                DSUy.del({x.se,sto[x].se});
            }
        }
        return;
    }
    
    int mid = (l + r) / 2;
    
    walk(2 * i,l,mid);
    walk(2 * i + 1,mid + 1,r);

    for (auto x: seg[i]){
        if (s.find(x) != s.end()){
            s.erase(s.find(x));
            DSUx.del({x.fi,sto[x].fi});
            DSUy.del({x.se,sto[x].se});
        }
    }
}

signed main(){
    // freopen("connect.in", "r", stdin);
    // freopen("connect.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    DSUx.init();
    DSUy.init();
    
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        if (DSUx.root[x] == 0){
            DSUx.root[x] = x;
            DSUx.sz[x] = 1;
        }
        if (DSUy.root[y] == 0){
            DSUy.root[y] = y;
            DSUy.sz[y] = 1;
        }
        if (a[{x,y}] == 0){
            a[{x,y}] = i;
        }
        else{
            update(1,1,3e5,a[{x,y}],i,{x,y});
            // cout << x << " " << y << ' ' << a[{x,y}] << " " << i << endl;
            a[{x,y}] = 0;
        }
    }

    for (auto i: a){
        if (i.se != 0){
            update(1,1,test,i.se,test,i.fi);
        }
    }
    a.clear();
    

    walk(1,1,test);

    return 0;
}