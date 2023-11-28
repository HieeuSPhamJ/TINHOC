#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

int n, m, test;
int rt[maxN];
vector <ii> adj[maxN];
int fa[maxN][20];
int mav[maxN][20];
int lvl[maxN];

void DFS(int node, int daddy){
    // cout << node << " " << daddy << endl;
    for (auto newNode: adj[node]){
        if (newNode.se == daddy){
            continue;
        }
        // cout << newNode.se << ' ' << node << " " << fa[newNode.se][0] << endl;
        fa[newNode.se][0] = node;
        lvl[newNode.se] = lvl[node] + 1;
        mav[newNode.se][0] = newNode.fi;
        DFS(newNode.se, node);
    }
}

void init(){
    lvl[0] = -1;
    fa[1][0] = 0;
    for (int j = 1; j <= log2(n); j++){
        for (int i = 1; i <= n; i++){
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
            // cout << i << " " << j << ": " << fa[i][j - 1] << endl;
            mav[i][j] = max(mav[i][j - 1], mav[fa[i][j - 1]][j - 1]);
        }
    }
}

ii LCA(int a, int b){
    int ma = 0;
    if (lvl[a] < lvl[b]){
        swap(a,b);
    }
    for (int i = log2(lvl[a]); i >= 0; i--){
        if (lvl[fa[a][i]] >= lvl[b]){
            ma = max(ma, mav[a][i]);
            a = fa[a][i];         
            // cout << a << " " << b << " " << ma << endl;
        }
    }
    // return {-1,-1};
    if (a == b){
        return {a,ma};
    }

    for (int i = log2(lvl[a]); fa[a][0] != fa[b][0]; i--){
        if (fa[a][i] != fa[b][i]){
            ma = max(ma, mav[a][i]);
            ma = max(ma, mav[b][i]);
            a = fa[a][i];
            b = fa[b][i];
            // cout << a << " " << b << " " << ma << endl;
        }
    }
    ma = max(ma,mav[a][0]);
    ma = max(ma,mav[b][0]);
    return {fa[a][0],ma};
}

int find(int u){
    if (u == rt[u]){
        return u;
    }
    return rt[u] = find(rt[u]);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        rt[i] = i;
    }

    vector <pair<int,ii>> ls;

    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        ls.push_back({w,{a,b}});
    }
    sort(all(ls));
    int total = 0;
    for (auto i: ls){
        int a = i.se.fi;
        int b = i.se.se;
        a = find(a);
        b = find(b);
        if (a == b){
            continue;
        }
        total += i.fi;
        rt[a] = b;
        
        a = i.se.fi;
        b = i.se.se;
        int w = i.fi;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
        
        // cout << a << " " << b << " " << w << endl;
    }
    
    DFS(1,1);
    init();

    // for (int i = 1; i <= n; i++){
        // cout << i << ": " << lvl[i] << endl; 
        // for (int j = 0; j <= 3; j++){
        //     cout << fa[i][j] << " ";
        // }
        // cout << endl;
    // }

    // cout << LCA(4,5).se << endl;
    // cout << total << endl;
    int test;
    cin >> test;
    while(test--){
        int a, b;
        cin >> a >> b;
        ii lca = LCA(a,b);
        // cout << a << " = " << b << endl;
        cout << total - lca.se << endl;
        // cout << lca.fi << " " << lca.se << endl;
    }
    
    return 0;
}