#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define all(x) x.begin(), x.end()
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;
int mod,sum;


int dp[maxN][510];
int trace[maxN][510];
map <ii,vector<ii>> adj;
vector <int> ans;
// int cntLim = 0;

void dfs(ii t){
    // cntLim++;
    
    // cout << t.fi << " " << t.se << endl;
    vector <pair <int,ii>> lists;
    for (int i = 0; i <= 9; i++){
        ii nu = t;
        nu.fi += i;
        (nu.se = nu.se * 10 + i) %= mod;
        if (nu.fi > sum){
            continue;
        }
        // cout << nu.fi << "," << nu.se << "|";
        if (trace[t.fi][t.se] == trace[nu.fi][nu.se] + 1){
            lists.push_back({i,nu});
        }
    }
    if (lists.empty()){
        return;
    }
    // if (cntLim >= 10){
    //     return;
    // }
    sort(all(lists));

    // for (auto i: lists){
    //     cout << i.se.fi << " " << i.se.se << endl;
    // }
    ans.push_back(lists.front().fi);
    dfs(lists.front().se);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> mod >> sum;

    queue <ii> q;
    q.push({0,0});
    dp[0][0] = 1;
    while(!q.empty()){
        ii t = q.front();
        q.pop();
        // cout << "With: " << t.fi << " " << t.se << endl;
        for (int i = 0; i <= 9; i++){
            ii nu = t;
            nu.fi += i;
            (nu.se = nu.se * 10 + i) %= mod;
            if (nu.fi > sum){
                continue;
            }
            adj[nu].push_back(t);
            adj[t].push_back(nu);
            if (dp[nu.fi][nu.se] == 0){
                // cout << nu.fi << "," << nu.se << " ";
                dp[nu.fi][nu.se] = dp[t.fi][t.se] + 1;
                q.push(nu);
            }
        }
        // cout << endl;
    }

    if (dp[sum][0] == 0){
        cout << -1 << endl;
        return 0;
    }


    q.push({sum,0});

    trace[sum][0] = 1;

    while(!q.empty()){
        ii t = q.front();
        q.pop();
        // cout << "With: " << t.fi << " " << t.se << endl;
        for (auto nu: adj[t]){
            if (dp[nu.fi][nu.se] + 1 == dp[t.fi][t.se]){
                trace[nu.fi][nu.se] = trace[t.fi][t.se] + 1;
                q.push(nu);
            }
        }
        // cout << endl;
    }

    // for (int i = 0; i <= sum; i++){
    //     for (int j = 0; j <= mod; j++){
    //         cout << trace[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    dfs({0,0});

    for (auto i: ans){
        cout << i;
    }
    

    return 0;
}