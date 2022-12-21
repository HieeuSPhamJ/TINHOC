#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int dp[2][maxN];
vector <ii> trace[2][maxN];
vector <int> adj[maxN];
int underchild[maxN];

void dfs(int node, int father){
    /*
    0: là th node là đỉnh cuối của đương thẳng chính
    1: node không phải là đỉnh cuối của đường thẳng chính
    */
    vector<int> lists;

    for (auto i: adj[node]){
        if (i == father){
            continue;
        }
        dfs(i,node);
        lists.push_back(i);

    }

    cout << "#NODE: " << node << endl;

    for (auto i: lists){
        cout << i << " ";
    }
    cout << endl;

    if (lists.empty()){
        dp[0][node] = 0;
        dp[1][node] = 0;
    }
    else{
        dp[0][node] = 0;
        int ok = 0;
        for (auto i: lists){
            dp[0][node]++;
            if (dp[0][i] <= dp[1][i]){
                dp[0][node] += dp[0][i];
                trace[0][node].push_back({0,i});
                cout << "select 0: " << dp[0][i] << endl;
                ok = 1;
            }
            else{
                dp[0][node] += dp[1][i];
                trace[0][node].push_back({1,i});
                cout << "select 1: " << dp[1][i] << endl;
            }
        }
        dp[0][node] -= ok;
        if (lists.size() == 2){
            dp[1][node] = min(dp[1][node], dp[0][lists[0]] + dp[0][lists[1]]);
        }
    }

    cout << dp[0][node] << " " << dp[1][node] << endl;

    
    cout << endl;
}

void tryvet(int type, int node){
    int ok = 0;
    for (auto i: trace[type][node]){
        tryvet(i.fi, i.se);
        ok = max(ok, i.fi);
    }
    cout << "t: " << type << " " << node << endl;
    if (type == 1){
        return;
    }
    underchild[node] = underchild[trace[type][node][0].se];
    for (int i = 1; i < trace[type][node].size(); i++){
        auto t = trace[type][node][i];
        cout << node << " " << t.se << " " << underchild[node] << " " << t.se << endl;
        underchild[node] = underchild[t.se];
    }

    if (ok == 0){
        cout << trace[type][node][0].se << " " << node << " " << underchild[node] << " " << node << endl;
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
        
        for (int i = 1; i <= n; i++){
            dp[0][i] = dp[1][i] = 1e18;
            adj[i].clear();
            underchild[i] = i;
        }
        for (int i = 1; i < n; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1,1);

        // cout << min(dp[0][1], dp[1][1]) << endl;

        if (dp[0][1] <= dp[1][1]){
            tryvet(0,1);
        }   
        else{
            tryvet(1,1);
        }
    }
    return 0;
}