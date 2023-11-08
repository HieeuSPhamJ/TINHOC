#include<bits/stdc++.h>
// #define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 4e5 + 10;
const int inf = 1e9;

int n, k;
vector <int> adj[maxN];
int v[maxN];
vector <int> lists;
int dp[2][maxN][2];
int sum[maxN];
int MID;
int RES;
ii dones[maxN];

void dfs(int nu, int fa){
    
    dp[0][nu][0] = 1;
    dp[0][nu][1] = 0;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs(i,nu);
        dp[0][nu][0] += dp[0][i][0];
        dp[0][nu][1] = max(dp[0][nu][1], dp[0][i][1]);
    }
    if (dp[0][nu][1] > 0){
        dp[0][nu][1] += dp[0][nu][0];
        dp[0][nu][0] = 0;
    }
    if (v[nu] < MID){
        dp[0][nu][0] = 0;
        dp[0][nu][1] = 1;
        // cout << "!" << nu << " " << v[nu] << ": " << dp[0][nu][0] << " " << dp[0][nu][1] << endl;
        return;
    }
    // cout << nu << " " << v[nu] << ": " << dp[0][nu][0] << " " << dp[0][nu][1] << endl;
}

void erase(ii &s, int v){
    if (s.fi == v){
        s.fi = s.se;
        s.se = -1;
    }
    else if (s.se == v){
        s.se = -1;
    }
}

void insert(ii &s, int v){
    if (s.fi == -1){
        s.fi = v;
    }
    else if (s.se == -1){
        s.se = v;
    }
    else if (v > s.fi){
        s.se = s.fi;
        s.fi = v;
    }
    else if (v > s.se){
        s.se = v;
    }
    if (s.se > s.fi){
        swap(s.fi,s.se);
    }
}

void print(ii s){
    cout << s.fi << " " << s.se << endl;
}
void reroot(int nu, int fa){
    if (nu != fa){
        // cout << "With: " << nu << endl;
        // solve father
        dp[1][fa][0] = 0;
        dp[1][fa][1] = 1;
        if (v[fa] >= MID){
            swap(dp[1][fa][0], dp[1][fa][1]);
            ii s = dones[fa];
            dp[1][fa][0] += (sum[fa] - dp[0][nu][0]);
            erase(s,dp[0][nu][1]);
            // print(s);
            if (s.fi != -1){
                dp[1][fa][1] = s.fi;
            }
            if (dp[1][fa][1] > 0){
                dp[1][fa][1] += dp[1][fa][0];
                dp[1][fa][0] = 0;
            }
        }
        // cout << "fa " << dp[1][fa][0] << " " << dp[1][fa][1] << endl;


        // solve nu

        dp[1][nu][0] = 1;
        dp[1][nu][1] = 0;
        for (auto i: adj[nu]){
            if (i == fa){
                dp[1][nu][0] += dp[1][i][0];
                dp[1][nu][1] = max(dp[1][nu][1], dp[1][i][1]);
                continue;
            }
            dp[1][nu][0] += dp[0][i][0];
            dp[1][nu][1] = max(dp[1][nu][1], dp[0][i][1]);
        }
        if (dp[1][nu][1] > 0){
            dp[1][nu][1] += dp[1][nu][0];
            dp[1][nu][0] = 0;
        }
        if (v[nu] < MID){
            dp[1][nu][0] = 0;
            dp[1][nu][1] = 1;
        }
        // cout << nu << ": " << dp[1][nu][0] << " " << dp[1][nu][1] - 1 << endl;
        RES = max({RES, dp[1][nu][0], dp[1][nu][1] - 1});
    }

    // init father
    for (auto i: adj[nu]){
        if (i == fa){
            sum[nu] += dp[1][i][0];
            insert(dones[nu], dp[1][i][1]);
            continue;
        }
        sum[nu] += dp[0][i][0];
        insert(dones[nu], dp[0][i][1]);
    }
    // cout << "in: " << endl;
    // print(dones[nu]);

    // change to child
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        reroot(i,nu);
    }
}


bool check(int mid){
    // cout << "check " << mid << endl;
    RES = 0;
    MID = mid;
    for (int i = 1; i <= n; i++){
        dones[i] = {-1,-1};
        sum[i] = dp[0][i][0] = dp[0][i][1] = dp[1][i][0] = dp[1][i][1] = 0;
    }
    dfs(1,1);
    // cout << endl;
    RES = max(dp[0][1][0], dp[0][1][1] - 1);
    dp[1][1][0] = dp[0][1][0];
    reroot(1,1);
    // cout << " =>" << RES << endl;
    return RES >= k;

}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("dfs.inp", "r")) {
        freopen("dfs.inp", "r", stdin);
        freopen("dfs.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
        lists.push_back(v[i]);
    }
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    sort(all(lists));
    lists.erase(unique(all(lists)), lists.end());
    int res = 0;
    int l = 0;
    int r = (int)lists.size() - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if (check(lists[mid])){
            l = mid + 1;
            res = mid;
        }
        else{
            r = mid - 1;
        }
    }
    // cout << check(4) << endl;
    cout << lists[res] << endl;
    return 0;
}