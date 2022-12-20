#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define rall(x) x.begin(), x.end()
using namespace std;

const int maxN = 2 * 1e5 + 10;

vector <int> adj[maxN];

int dp[maxN];
int ans = 1;
int isleaf[maxN];

void dfs(int node, int father){
    int ok = 1;
    int okall = 1;
    vector <int> lists;
    for (auto nu: adj[node]){
        if (nu == father){
            continue;
        }
        ok = 0;
        dfs(nu,node);
        if (isleaf[nu] == 0){
            okall = 0;
        }
        lists.push_back(dp[nu]);
    }
    
    isleaf[node] = ok;
    // cout << "Node: " << node << " " << ok << endl;
    sort(rall(lists));
    ok = 1;

    // for (auto i: lists){
    //     cout << i << " ";
    // }
    // cout << endl;

    if (lists.size() >= 2){
        ans = max(ans, lists[0] + lists[1] + (int)(lists.size() - 2));
    }
    if (!lists.empty()){
        dp[node] = max(dp[node], (int)(lists.back() + lists.size() - 1));
    }
    if (okall == 0){
        ans = max(ans,dp[node] + 1 + (node != father));
    }
    else{
        ans = max(ans, dp[node]);
    }
    // cout << dp[node] << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,1);

    if (n == 2){
        cout << 1 << endl;
        return 0;
    }

    cout << ans;
    return 0;
}