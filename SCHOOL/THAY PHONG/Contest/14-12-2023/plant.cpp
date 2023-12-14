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

int n = 1;
int st[maxN];
int en[maxN];
vector <int> adj[maxN];

void dfs(int nu){
    static int cnt = 1;
    st[nu] = cnt;
    cnt++;
    for (auto i: adj[nu]){
        dfs(i);
    }
    en[nu] = cnt - 1;
}

int seg[maxN * 4];
int lazy[maxN * 4];

void setLazy(int i){
    int val = lazy[i];
    lazy[i] = -1;
    if (val == -1){
        return;
    }
    lazy[2 * i] = val;
    lazy[2 * i + 1] = val;
    seg[2 * i] = val;
    seg[2 * i + 1] = val;
}


void update(int i, int left, int right, int _left, int _right, int val){
    if (right < _left or _right < left){
        return;
    }
    if (_left <= left and right <= _right){
        seg[i] = val;
        lazy[i] = val;
        return;
    }
    setLazy(i);
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
    setLazy(i);
    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return (t1 + t2);
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
    int m;
    cin >> m;
    vector <ii> ask;
    for (int i = 1; i <= m; i++){
        char t;
        int x;
        cin >> t >> x;
        if (t == '+'){
            adj[x].push_back(n);
            ask.push_back({1,n});
            n++;
        }
        else if (t == '-'){
            ask.push_back({-1,x});
        }
        else{
            ask.push_back({0,x});
        }
    }

    dfs(0);

    update(1,1,n,st[0], st[0], 1);

    for (auto i: ask){
        if (i.fi == 1){
            update(1,1,n,st[i.se], st[i.se],1);
        }
        else if (i.fi == -1){
            update(1,1,n,st[i.se], en[i.se],0);
        }
        else{
            cout << get(1,1,n,st[i.se], en[i.se]) << endl;
        }
    }

    return 0;
}