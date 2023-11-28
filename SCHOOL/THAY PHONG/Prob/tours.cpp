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

const int maxN = 1e6 + 10;

vector <int> adj[maxN];
int rt[maxN];

int find(int nu){
    if (nu == rt[nu]){
        return nu;
    }
    return rt[nu] = find(rt[nu]);
}

int mk[maxN];

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
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector <int> ls;
    for (int i = 1; i <= n; i++){
        rt[i] = i;
        int x;
        cin >> x;
        ls.push_back(x);
    }

    mk[ls.back()] = 1;
    ls.pop_back();
    int com = 1;
    vector <string> res;
    res.push_back("YES");
    while(ls.size()){
        int t = ls.back();
        mk[t] = 1;
        com++;
        ls.pop_back();
        // cout << "with: " << t << endl;
        for (auto nu: adj[t]){
            if (mk[nu]){
                int u = find(t);
                int v = find(nu);
                if (u == v){
                    continue;
                }
                // cout << nu << " " << t << endl;
                rt[u] = v;
                com--;
            }
        }
        if (com == 1){
            res.push_back("YES");
        }
        else{
            res.push_back("NO");    
        }
    }

    reverse(all(res));
    for (auto i: res){
        cout << i << endl;
    }
    return 0;
}