#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int ans = 0;
vector <int> adj[maxN];
priority_queue <ii> myHeap;
int dp[maxN];
int a[maxN];

void init(int node, int father){
    dp[node] = 1;
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        init(newNode, node);
        dp[node] += dp[newNode];
    }
    
}


void DFS(int node, int father){
    dp[node] = a[node];
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        DFS(newNode, node);
        dp[node] += dp[newNode];
    }
    if (a[node] == 0){
        // cout << node << ": " << dp[node] << endl;
        ans += dp[node];
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); 
    }
    init(1,1);
    for (int i = 1; i <= n; i++){
        a[i] = 1;
        // dp[i]--;
        // cout << i << ": " << dp[i] << endl;
        myHeap.push({dp[i],i});
    }
    k = n - k;
    
    while(k--){
        // ans += myHeap.top().fi;
        a[myHeap.top().se] = 0;
        cout << myHeap.top().se << ' ';
        myHeap.pop();
    }
    cout << endl;
    DFS(1,1);

    cout << ans;
    return 0;
}