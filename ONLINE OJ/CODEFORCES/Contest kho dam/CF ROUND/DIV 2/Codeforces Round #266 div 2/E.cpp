#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int n, test;
int root[maxN];
int height[maxN];
vector <ii> ask[maxN];
int used[maxN];
int father[maxN][20];
vector <int> adj[maxN];

int findRoot(int x){
    if (root[x] == x){
        return x;
    }
    return root[x] = findRoot(root[x]);
}

void dfs(int node, int dad){
    used[node] = 1;
    for (auto i: adj[node]){
        if (i == dad){
            continue;
        }
        
        father[i][0] = node;
        height[i] = height[node] + 1;
        dfs(i,node);
    }
}

void init(){
    height[0] = -1;
    for (int j = 1; j <= log2(n); j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
        }
    }
}

int lca(int a, int b){
    if (height[a] < height[b]){
        swap(a,b);
    }
    for (int i = log2(height[a]); i >= 0; i--){
        if (height[father[a][i]] >= height[b]){
            a = father[a][i];
        }
    }

    if (a == b){
        return a;
    }

    for (int i = log2(height[a]); father[a][0] != father[b][0]; i--){
        if (father[a][i] != father[b][i]){
            a = father[a][i];
            b = father[b][i];
        }
    }

    return father[a][0];
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> test;
    
    for (int i = 1; i <= n; i++){
        root[i] = i;
    }

    vector <int> docum;
    vector <pair <int,ii>> Query;

    for (int tt = 1; tt <= test; tt++){
        int t;
        cin >> t;
        if (t == 1){
            int x, y;
            cin >> x >> y;
            Query.push_back({1,{x,y}});
            adj[x].push_back(y);
            adj[y].push_back(x);
            used[x] = 1;
        }
        else if (t == 2){
            int x;
            cin >> x;
            Query.push_back({2,{(int)docum.size(),(int)docum.size()}});
            docum.push_back(x);
        }
        else{
            int x, i;
            cin >> x >> i;
            ask[i - 1].push_back({tt,x});
        }
    }

    for (int i = 1; i <= n; i++){
        if (used[i] == 0){
            dfs(i,i);
        }
    }
    init();
    // for (int i = 1; i <= n; i++){
    //     cout << i << ": " << height[i] << endl;
    // }

    vector <ii> ans;

    for (auto q: Query){
        int t = q.fi;
        if (t == 1){
            int x = q.se.fi;
            int y = q.se.se;
            int u = findRoot(x);
            int v = findRoot(y);
            root[u] = v;
        }
        else if (t == 2){
            int j = q.se.fi;
            int source = docum[j];
            for (auto i: ask[j]){
                int ok = 0;
                // cout << source << " " << i.se << endl;
                if (source == i.se){
                    ok = 1;
                }
                if (findRoot(source) == findRoot(i.se)){
                    if (lca(source,i.se) == i.se){
                        ok = 1;
                    }
                    
                }
                ans.push_back({i.fi, ok});
            }
        }
    }


    sort(ans.begin(), ans.end());

    for (auto i: ans){
        if (i.se == 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}