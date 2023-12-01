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

const int maxN = 2e5 + 10;

int n,m;
vector <int> adj[maxN];
int num[maxN];
int low[maxN];
int cnt = 0;
set <ii> ls;
set <ii> era;

void tarjan(int nu, int fa){
    cnt++;
    num[nu] = low[nu] = cnt;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        if (num[i]){
            low[nu] = min(low[nu], num[i]);
        }
        else{
            tarjan(i, nu);
            low[nu] = min(low[nu], low[i]);
            if (low[i] == num[i]){
                // cout << nu << " " << i << endl;
                if (ls.find({min(i,nu), max(i,nu)}) != ls.end()){
                    ls.erase(ls.find({min(i,nu), max(i,nu)}));
                    era.insert({min(i,nu), max(i,nu)});
                }
            }
        }
    }
}

int rt[maxN];
int va[maxN];

int find(int nu){
    if (nu == rt[nu]){
        return nu;
    }
    return rt[nu] = find(rt[nu]);
}

void mini(){
    set <ii> ts = ls;
    ls.clear();
    for (auto i: ls){
        int a = find(i.fi);
        int b = find(i.se);
        if (a > b){
            swap(a,b);
        }
        ls.insert({a,b});
    }
    for (auto i: era){
        int a = find(i.fi);
        int b = find(i.se);
        if (a > b){
            swap(a,b);
        }
        ls.insert({a,b});
    }
}


int res = 0;
int sz[maxN];

void dfs(int nu, int fa){
    sz[nu] = va[nu];
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs(i,nu);
        sz[nu] += sz[i];
        int a = sz[i];
        int b = n - a;
        res += (a * b - 1);
    }
}

int getcnt(int nu){
    int res = 1;
    num[nu] = -1;
    for (auto i: adj[nu]){
        if (num[i] != -1){
            res += getcnt(i);
        }
    }
    return res;
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
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ls.insert({min(a,b), max(a,b)});
    }
    
    int isconnected = 0;
    
    for (int i = 1; i <= n; i++){
        if (num[i] == 0){
            tarjan(i,i);
            isconnected++;
        }
    }
    if (isconnected > 2){
        cout << 0 << endl;
        return 0;
    }
    if (isconnected > 1){
        int x = getcnt(1);
        // cout << x << endl;
        cout << (int)ls.size() * (n - x) * x << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++){
        adj[i].clear();
        rt[i] = i;
        va[i] = 1;
    }

    for (auto i: ls){
        // cout << i.fi << ' ' << i.se << endl;
        int a = find(i.fi);
        int b = find(i.se);
        if (a == b){
            continue;
        }
        if (a > b){
            swap(a,b);
        }
        va[b] += va[a];
        rt[a] = b;
    }
    
    for (int i = 1; i <= n; i++){
        if (i != find(i)){
            va[i] = 1;
        }
    }

    if (isconnected){
        int x = ls.size();
        res += x * (n * (n - 1) / 2 - m);
        // cout << x << endl;
    }

    
    mini();

    for (auto i: ls){
        // cout << i.fi << ' ' << i.se << endl;
        adj[i.fi].push_back(i.se);
        adj[i.se].push_back(i.fi);
    }


    if (isconnected){
        dfs(n,n);
    }

    cout << res << endl;

    return 0;
}