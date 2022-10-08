#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

vector <ii> adj[maxN];
int dp[maxN];
int tempAns[maxN];
int ans;

void DFS(int node, int father){
    // cout << node << " ";
    dp[node] = 0;
    tempAns[node] = 0;
    int a = 0;
    int b = 0;
    for (auto newNode: adj[node]){
        if (newNode.se == father){
            continue;
        }
        DFS(newNode.se, node);
        int newLength = dp[newNode.se] + newNode.fi;
        dp[node] = max(dp[node], newLength);
        if (newLength > a){
            b = a;
            a = newLength;
        }
        else{
            b = max(b,newLength);
        }
    }
    tempAns[node] = a + b;
    ans = max(ans,tempAns[node]);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while (test--){
        int n;
        cin >> n;
        
        ans = 0;
        for (int i = 1; i <= n; i++){
            adj[i].clear();
        }
        
        for (int i = 1; i < n; i++){
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({w,b});
            adj[b].push_back({w,a});
        }

        DFS(1,1);
        cout << endl;

        cout << ans;
        cout << endl;
    }
    return 0;
}