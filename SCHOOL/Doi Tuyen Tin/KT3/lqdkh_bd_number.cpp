#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3 * 1e3 + 10;

string a,b;
int dp[maxN][maxN];
vector <ii> adj[maxN][maxN];
ii vis[maxN][maxN];
ii d[]{
    {0,-1},
    {-1,0},
    {-1,-1}
};

void add(ii a, ii b){
    adj[a.fi][a.se].push_back(b);
}

void dfs(ii nu){
    if (min(nu.fi,nu.se) <= 0){
        return;
    }
    cout << a[nu.fi];
    // cout << endl;
    pair <ii,char> st = {{0,0},'0'};
    for (auto i: adj[nu.fi][nu.se]){
        if (a[i.fi] >= st.se){
            // cout << st.se << " " << a[i.fi] << endl;
            st.se = a[i.fi];
            st.fi = i;
        }
    }
    dfs(st.fi);
}

signed main(){
    // freopen("number.INP", "r", stdin);
    // freopen("number.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b; 
    int n = a.length();
    int m = b.length();
    a = '.' + a;
    b = '.' + b;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i] == b[j]){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }   
    
    queue <ii> q;
    pair <ii,char> st = {{0,0},'0'};
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i] == b[j] and dp[i][j] == dp[n][m]){
                q.push({i,j});
                vis[i][j] = {i,j};
            }
            else{
                vis[i][j] = {0,0};
            }
            if (a[i] == b[j] and dp[i][j] == 1){
                if (a[i] > st.se){
                    st.se = a[i];
                    st.fi = {i,j};
                }
            }
        }
    }

    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int limit = 0;
    while(!q.empty()){
        ii t = q.front();
        q.pop();
        limit++;
        // cout << "With: " << t.fi << "," << t.se << endl;
        for (int i = 0; i < 3; i++){
            ii nu = t;
            nu.fi += d[i].fi;
            nu.se += d[i].se;
            if (min(nu.fi,nu.se) <= 0 or vis[nu.fi][nu.se] != make_pair(0,0)){
                continue;
            }
            // cout << nu.fi << "," << nu.se << " "; 
            if (dp[nu.fi][nu.se] + 1 == dp[t.fi][t.se]){
                vis[nu.fi][nu.se] = nu;
                add(nu,vis[t.fi][t.se]);
                q.push(nu);
            }
            else if (dp[nu.fi][nu.se] == dp[t.fi][t.se]){
                q.push(nu);
                vis[nu.fi][nu.se] = vis[t.fi][t.se];
            }
        }
        // cout << endl;
    }
    // cout << limit << endl;
    dfs(st.fi);


    return 0;
}