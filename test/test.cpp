#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 7;

vector <int> adj[maxN];
int ans = 0;
int lacon[maxN];
int la[maxN];
int isla[maxN];
int dp[maxN];
int countBru;
int sus = 0;

int choose(int x){
    if (x == 0){
        return 0;
    }
    return (1 << (x - 1));
}

void dfs(int node, int father){
    int checkLa = 1;
    int fullLa = 1;
    int child = 0;
    for (auto newNode: adj[node]){
        if (father == newNode){
            continue;
        }
        child++;
        checkLa = 0;
        dfs(newNode,node);
        if (isla[newNode] == 0){
            fullLa = 0;
        }

        dp[node] += dp[newNode];
        lacon[node] += isla[newNode];
        la[node] += la[newNode];
    }
    if ((child - lacon[node]) >= 1 and (child - lacon[node]) % 2 == 0 and lacon[node] == 0){
        sus = 1;
    }
    // cout << node << ": " << isla[node] << endl;
    if (checkLa == 1){
        isla[node] = 1;
        la[node] = 1;
        fullLa = 0;
    }
    else if (fullLa){
        dp[node] += choose(lacon[node]);
    }
    else if (lacon[node] == 0 and child % 2 == 0){
        dp[node] = 1;
    }
    else if ((child - lacon[node]) % 2 == 0 and lacon[node] >= 1){
        // cout << "Spec 1" << ": " << node << endl;
        if ((child - lacon[node]) >= 1 and (child - lacon[node]) % 2 == 0){
            dp[node] = choose(lacon[node]) * dp[node];
            // cout << "nosus" << endl;
        }
        else{
            countBru += choose(lacon[node]);
        }
    }
    else if ((child - lacon[node]) % 2 == 1 and lacon[node] >= 1){
        // cout << "Spec 2" << ": " << node << endl;
        countBru += choose(lacon[node]) - 1;
    }
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    // freopen("JUNGLE.INP", "r", stdin);
    // freopen("JUNGLE.OUT", "w", stdout);
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

    // for (int i = 1; i <= n; i++){
    //     cout << i << ": " << dp[i] << endl;
    // }
    if (sus == 1){
        cout << 0;
        return 0;
    }
    cout << dp[1] + (1 << countBru) - 1;
    return 0;
}