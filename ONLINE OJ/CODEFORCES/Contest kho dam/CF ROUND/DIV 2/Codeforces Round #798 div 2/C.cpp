#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;


const int maxN = 3 * 1e5 + 10;

vector <int> adj[maxN];
int dp[maxN][3];

void DFS(int node, int father){
    dp[node][0] = 1;
    dp[node][1] = 0;
    int count = 0;
    int singleChild = -1;
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        count++;
        singleChild = newNode;
        DFS(newNode, node);
        dp[node][0] += dp[newNode][0];
    }
    if (count == 1){
        dp[node][1] = max(dp[node][1], dp[singleChild][0] - 1);
    }
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        dp[node][1] = max(dp[node][1], (dp[node][0] - dp[newNode][0] - 2) + dp[newNode][1]);
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
        int n;
        cin >> n;
        for (int i = 0; i <= n; i++){
            adj[i].clear();
            dp[i][0] = dp[i][1] = 0;
        }
        for (int i = 1; i < n; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        DFS(1,1);
        // for (int i = 1; i <= n; i++){
        //     cout << i << ": " << dp[i][0] << " " << dp[i][1] << endl;
            // cout << i << ": ";
            // for (auto j: adj[i]){
            //     cout << j << " ";
            // }
            // cout << endl;
        // }

        cout << dp[1][1] << endl;
    }
    return 0;
}