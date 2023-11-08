#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int rt[maxN];
int vin[maxN];
int ein[maxN];
int f[maxN];
int pre[maxN];

int n, m, k;
int check[2 * maxN];

int find(int u){
    if (u == rt[u]){
        return u;
    }
    return rt[u] = find(rt[u]);
}

int grundy(int n){
    return n % (k + 1);
}

void solve(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        rt[i] = i;
        vin[i] = 1;
        ein[i] = 0;
    }
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        int u = find(a);
        int v = find(b);
        if (u == v){
            ein[u]++;
            continue;
        }
        rt[v] = u;
        vin[u] += vin[v];
        ein[u] += ein[v] + 1;
    }
    set <int> s;
    for (int i = 1; i <= n; i++){
        s.insert(find(i));
    }

    vector <int> ls;

    for (auto i: s){
        ls.push_back(ein[i] - (vin[i] - 1));
    }
    int res = 0;
    for (auto i: ls){
        res = res xor grundy(i);
    }

    cout << (res != 0) << endl;
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
    int test = 4;
    while(test--){
        solve();
    }
    return 0;
}


/*

0
1
1
1
1
0
1
1
1
1
0
1
1
1
1
0


*/
