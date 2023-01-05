#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int lists[maxN];
int dp[maxN];
vector <int> adj[maxN];

void dfs(int node, int father){
    lists[dp[node]]++;
    for (auto i: adj[node]){
        if (father == i){
            continue;
        }
        dp[i] = dp[node] + 1;
        dfs(i,node);
    }
}

signed main(){
    freopen("PROTREE.INP", "r", stdin);
    freopen("PROTREE.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int test;
    cin >> test;
    for (int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        
    } 
    dfs(1,1);

    while(test--){
        int x;
        cin >> x;
        cout << lists[dp[x]] << endl;
    }
    return 0;
}