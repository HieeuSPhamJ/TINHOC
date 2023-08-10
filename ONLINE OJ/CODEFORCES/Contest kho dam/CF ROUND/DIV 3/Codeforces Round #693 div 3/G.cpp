#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int inf = 1e18;
const int maxN = 2 * 1e5 + 10;

vector <int> adj[maxN];
vector <int> invAdj[maxN];
int level[maxN];
int ans[maxN][3];

void dinhhuong(){
    queue <int> q;
    q.push(1);
    level[1] = 0;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for (auto i: adj[t]){
            if (level[i] == -1){
                level[i] = level[t] + 1;
                q.push(i);
            }
        }
    }
}

void dfs(int node, int temp, int Stop){
    // cout << node << endl;
    if (ans[node][Stop] != inf){
        // cout << "Lmao" << endl;
        return;
    }
    ans[node][Stop] = level[node];
    for (auto newNode: adj[node]){
        int newTemp = temp;
        int newStop = Stop;
        if (level[node] >= level[newNode]){
            newTemp++;
            newStop = 0;
        }
        // cout << newNode << " " << newTemp << endl;
        if (newTemp > Stop){
            continue;
        }
        if (ans[newNode][newStop] == inf){
            dfs(newNode, newTemp, newStop);
        }
        ans[node][Stop] = min(ans[node][Stop], ans[newNode][newStop]);
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        // cout << "==TEST==" << endl;
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            adj[i].clear();
            invAdj[i].clear();
            level[i] = -1;
            ans[i][0] = inf;
            ans[i][1] = inf;
        }

        for (int i = 1; i <= m; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            invAdj[b].push_back(a);
        }
        ans[1][0] = 0;
        ans[1][1] = 0;
        dinhhuong();
        // for (int i = 1; i <= n; i++){
        //     cout << "lvl " << i << " " << level[i] << endl; 
        // }
        for (int i = 2; i <= n; i++){
            for (int j = 0; j <= 1; j++){
                // cout << "With: " << i << " " << j << endl;
                dfs(i, 0, j);
            }
        }
        // dfs(3,0,0);
        // cout << ans[3][0] << " " << ans[3][1] << endl;
        // for (int i = 1; i <= n; i++){
        //     cout << ans[i][0] << " " << ans[i][1] << endl;
        // }
        for (int i = 1; i <= n; i++){
            cout << min(ans[i][0], ans[i][1]) << " ";
        }
        cout << endl;
    }
    return 0;
}