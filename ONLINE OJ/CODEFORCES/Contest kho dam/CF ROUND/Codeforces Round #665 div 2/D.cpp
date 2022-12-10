#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;
const int mod = 1e9 + 7;

int n;
vector <int> adj[maxN];
priority_queue <int, vector <int>, greater <int>> listV;
int dp[maxN];

void DFS(int node, int father){
    dp[node] = 1;
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        DFS(newNode, node);

        int num = (n - dp[newNode]) * dp[newNode];
        listV.push(num);

        // cout << node << " " << newNode << " " << num << endl;
        dp[node] += dp[newNode];
    }

}

void solve(){
    cin >> n;
    while(listV.empty() == 0){
        listV.pop();
    }
    for (int i = 1; i <= n; i++){
        dp[i] = 0;
        adj[i].clear();
    }
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    DFS(1,1);
    // for (int i = 1; i <= n; i++){
    //     cout << dp[i] << endl;
    // }
    // for (auto i: listV){
    //     cout << i << " ";
    // }
    // cout << endl << endl;

    int m;
    cin >> m;

    int ans = 0;
    vector <int> listPrime;
    for (int i = 1; i <= m; i++){
        int inp;
        cin >> inp;
        listPrime.push_back(inp);
        // listV.pop();
        // listV.push(t * inp);
    }
    sort(listPrime.rbegin(), listPrime.rend());
    for (auto i: listPrime){
        int t = listV.top();
        cout << i << " " << t << endl; 
        listV.pop();
        listV.push(t * i);
    }
    while(listV.empty() == 0){
        ans += listV.top();
        cout << listV.top() << " ";
        listV.pop();
    }
    cout << endl;
    cout << ans;

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
        solve();
        cout << endl;
    }
    return 0;
}