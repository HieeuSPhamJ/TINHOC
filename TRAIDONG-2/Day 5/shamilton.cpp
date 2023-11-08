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

struct Edge {
    int target, id;
    Edge(int _target, int _id): target(_target), id(_id) {}
};

vector<Edge> adj[30];
bool used_edge[200010]; 

list<int> euler_walk(int u) {
    list<int> ans;
    ans.push_back(u);
    while (!adj[u].empty()) {
        int v = adj[u].back().target;
        int eid = adj[u].back().id;
        adj[u].pop_back();
        if (used_edge[eid]) continue;
        used_edge[eid] = true;
        u = v;
        ans.push_back(u);
    }
    for (auto it = ++ans.begin(); it != ans.end(); ++it) {
        auto t = euler_walk(*it);
        t.pop_back();  
        ans.splice(it, t);
    }
    
    return ans;
}

vector <int> sto[30][30];

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
    int n;
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        ii t = {s.front() - 'a', s.back() - 'a'};
        adj[t.fi].push_back({t.se, i});
        sto[t.fi][t.se].push_back(i);
        s = t.fi;
    }

    list <int> l = euler_walk(s);
    vector <int> ls;
    for (auto i: l){
        ls.push_back(i);
    }

    if ((int)ls.size() < n + 1){
        cout << -1 << endl;
        return 0;
    }
    
    for (int i = 1; i < (int)ls.size(); i++){
        cout << sto[ls[i - 1]][ls[i]].back() << " ";
        sto[ls[i - 1]][ls[i]].pop_back();
    }

    

    return 0;
}