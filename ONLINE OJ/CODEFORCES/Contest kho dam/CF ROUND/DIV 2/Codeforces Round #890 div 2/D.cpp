#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 5010;

int n;
vector <int> adj[maxN];
int dp[maxN];

void dfs(int nu, int fa){
    dp[nu] = 1;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs(i,nu);
        dp[nu] += dp[i];
    }
}

bool mk[maxN];

int cal(vector <int> &ls){
    memset(mk, 0, sizeof(mk));
    mk[0] = 1;
    int sum = 0;
    for (auto i: ls){
        sum += i;
        for (int x = maxN - 1 - i; x >= 0; x--){
            mk[i + x] = mk[x];
        }
    }
    int del = 1e18;
    int res = 0;
    for (int i = 0; i < maxN; i++){
        if (mk[i]){
            if (abs((sum - i) - i) < del){
                del = abs((sum - i) - i);
                res = i;
            }
        }
    }
    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 2; i <= n; i++){
        int x;
        cin >> x;   
        adj[i].push_back(x);
        adj[x].push_back(i);
        
    }

    dfs(1,1);
    int res = 0;
    for (int i = 1; i <= n; i++){
        vector <int> ls;
        // cout << " With " << i << ": " << dp[i] << endl;
        for (auto j: adj[i]){
            if (dp[j] > dp[i]){
                continue;
            }
            // cout << dp[j] << " ";
            ls.push_back(dp[j]);
        }
        // cout << endl;

        int x = cal(ls);
        int y = dp[i] - 1 - x;

        // cout << x << " - " << y << endl;
        res += x * y;
    }
    cout << res << endl;
    return 0;
}

/*
12 + 1
*/