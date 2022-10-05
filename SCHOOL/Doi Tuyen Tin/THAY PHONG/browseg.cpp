#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int dp[maxN];
int n, m;
int check[maxN];
vector <int> adj[maxN];
int res;

void DFS(int node, int father){
    dp[node] = 1;
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        DFS(newNode, node);
        dp[node] += dp[newNode];
        check[node] = max(check[node], check[newNode]);
    }
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x, y;
    cin >> n >> x >> y;
    int ans = n * (n - 1);
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    check[y] = 1;
    DFS(x,x);
    int t1 = n, t2 = dp[y];
    for (auto i: adj[x]){
        if (check[i]){
            // cout << i << endl;
            t1 = t1 - dp[i];
            break;
        }
    }
    // cout << t1 << " " << t2 << endl;
    cout << ans - t1 * t2;


    return 0;
}