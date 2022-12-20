#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

int n, test;
vector <int> adj[maxN];
int father[maxN][20];
int level[maxN];
ii a[maxN];

void DFS(int node, int daddy){
    for (auto newNode: adj[node]){
        if (newNode == daddy){
            continue;
        }
        father[newNode][0] = node;
        level[newNode] = level[node] + 1;
        DFS(newNode, node);
    }
}

void init(){
    level[0] = -1;
    for (int j = 1; j <= log2(n); j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
        }
    }
}

int LCA(int a, int b){
    if (level[a] < level[b]){
        swap(a,b);
    }
    for (int i = log2(level[a]); i >= 0; i--){
        if (level[father[a][i]] >= level[b]){
            a = father[a][i];
        }
    }

    if (a == b){
        return a;
    }

    for (int i = log2(level[a]); father[a][0] != father[b][0]; i--){
        if (father[a][i] != father[b][i]){
            a = father[a][i];
            b = father[b][i];
        }
    }

    return father[a][0];
}

signed main(){
    // freopen("MEETING.inp", "r", stdin);
    // freopen("MEETING.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi;
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i].se;
    }
    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        // cout << x << ' ' << y << endl;
    }

    DFS(1,1);
    init();

    // cout << LCA(6,7) << endl;

    for (int te = 1; te <= test; te++){
        int x, y;
        cin >> x >> y;
        int lca = LCA(x,y);
        if (x == lca or y == lca){
            if (y == lca){
                swap(x,y);
            }
        }
        // cout << x << " " << y << " " << lca << endl;
        vector <int> lists[2];
        while(x != lca){
            lists[0].push_back(a[x].fi);
            lists[1].push_back(a[x].se);
            x = father[x][0];
        }
        while(y != lca){
            lists[0].push_back(a[y].fi);
            lists[1].push_back(a[y].se);
            y = father[y][0];
        }
        lists[0].push_back(a[lca].fi);
        lists[1].push_back(a[lca].se);
        sort(all(lists[0]));
        sort(all(lists[1]));

        // for (auto i: lists[0]){
        //     cout << i << " ";
        // }
        // cout << endl;
        
        // for (auto i: lists[0]){
        //     cout << i << " ";
        // }
        // cout << endl;

        int len = lists[1].size();
        int ans[3];
        ans[0] = 1e18;
        ans[1] = 1e18;
        for (int t = 0; t <= 1; t++){
            int median[3];
            median[0] = lists[t][(len - 1) / 2];
            median[1] = lists[t][(len - 1) / 2 + 1];
            for (int me = 0; me <= 1; me++){
                int tans = 0;
                for (auto i: lists[t]){
                    tans += abs(i - median[me]);
                }
                ans[t] = min(ans[t], tans);
            }
        }
        cout << ans[0] + ans[1] << endl;
    }

    return 0;
}
