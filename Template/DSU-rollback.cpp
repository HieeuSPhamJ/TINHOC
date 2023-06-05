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

int query[maxN];
map <ii,int> a;

int n, test;
set <ii> s;
vector <ii> seg[4 * maxN];

struct dsulmao{
    int root[maxN];
    int com = n;
    vector <ii> st;
    void init(){
        com = n;
        for (int i = 1; i < maxN; i++){
            root[i] = i;
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
        com--;
        // cout << com << endl;
        st.push_back({-1,-1});
    }
    void del(ii e){
        // cout << "- del "<< endl;
        while(st.back().fi != 0){
            // cout << st.back().fi << ' ' << st.back().se << endl;
            if (st.back().fi == -1){
                com++;    
            }
            else{
                root[st.back().fi] = st.back().se;
            }
            st.pop_back();
        }
        st.pop_back();
    }
};

dsulmao DSU;

void update(int i, int l, int r, int L, int R, ii v){
    // cout << l << ' ' << r << endl;
    if (r < L or R < l){
        return;
    }
    if (L <= l and r <= R){
        // cout << l << ' ' << r << ": " << v.fi << ' ' << v.se << endl;
        seg[i].push_back(v);
        return;
    }
    
    int mid = (l + r) / 2;

    update(2 * i,l,mid,L,R,v);
    update(2 * i + 1,mid + 1,r,L,R,v);
}

void walk(int i, int l, int r){
    for (auto x: seg[i]){
        // cout << l << "-" << r << endl;
        if (s.find(x) == s.end()){
            s.insert(x);
            // cout << "+" << x.fi << ' ' << x.se << endl;
            DSU.add(x);
        }
    }

    if (l == r){
        // cout << l << "-" << r << endl;
        if (query[l]){
            // cout << "With: " << l << endl;
            // for (auto x: s){
            //     cout << x.fi << " " << x.se << endl;
            // }
            cout << DSU.com << endl;
        }
        for (auto x: seg[i]){
            if (s.find(x) != s.end()){
                // cout << "-" << x.fi << ' ' << x.se << endl;
                s.erase(s.find(x));
                DSU.del(x);
            }
        }
        return;
    }
    
    int mid = (l + r) / 2;
    
    walk(2 * i,l,mid);
    walk(2 * i + 1,mid + 1,r);

    
    // cout << l << "-" << r << endl;
    for (auto x: seg[i]){
        if (s.find(x) != s.end()){
            // cout << "-" << x.fi << ' ' << x.se << endl;
            s.erase(s.find(x));
            DSU.del(x);
        }
    }
}

signed main(){
    // freopen("connect.in", "r", stdin);
    // freopen("connect.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> test;

    if (test == 0){
        return 0;
    }

    DSU.init();

    for (int i = 1; i <= test; i++){
        char t;
        cin >> t;
        if (t == '?'){
            query[i] = 1;
        }
        else{
            int x, y;
            cin >> x >> y;
            if (x > y){
                swap(x,y);
            }
            if (t == '+'){
                a[{x,y}] = i;
            }
            else{
                update(1,1,test,a[{x,y}],i,{x,y});
                a[{x,y}] = 0;
            }
        }   
    }

    for (auto i: a){
        if (i.se != 0){
            update(1,1,test,i.se,test,i.fi);
        }
    }
    a.clear();
    walk(1,1,test);
    

    // cout << "CONCAC" << endl;

    return 0;
}

/*
1 ?
2 + 1 2
3 + 2 3
4 + 3 4
5 + 4 5
6 + 5 1
7 ?
8 - 2 3
9 ?
10 - 4 5
11 ?
*/