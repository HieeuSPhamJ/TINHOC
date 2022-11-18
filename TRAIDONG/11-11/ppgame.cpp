#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ii pair <int,int>
#define iiii pair <ii,ii>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;


int n, m, mod;
int a[361][361];
// map <iiii,int> memo[3];
// map <iiii,bool> ison[3];

int memo[361][361][361][2];
bool ison[361][361][361][2];

iiii d[] = {
    {{0,1},{0,-1}},
    {{1,0},{-1,0}},
    {{0,1},{-1,0}},
    {{1,0},{0,-1}}
};

bool isEnd(iiii node){
    int ok = (n + m) % 2;
    int dis = abs(node.fi.fi - node.se.fi) + abs(node.fi.se - node.se.se);
    // cout << ok << " " << abs(node.fi.fi - node.se.fi) + abs(node.fi.se - node.se.se) << endl;
    return (dis == ok);
}

bool outGrid(iiii node){
    if (node.fi.fi < 1 or node.fi.fi > n){
        return 1;
    }
    if (node.se.fi < 1 or node.se.fi > n){
        return 1;
    }
    if (node.fi.se < 1 or node.fi.se > m){
        return 1;
    }
    if (node.se.se < 1 or node.se.se > m){
        return 1;
    }
    if (node.fi.fi > node.se.fi){
        return 1;
    }
    if (node.fi.se > node.se.se){
        return 1;
    }
    return 0;
}

bool isSame(iiii node){
    return (a[node.fi.fi][node.fi.se] == a[node.se.fi][node.se.se]);
}

void print(iiii node){
    cout << "{" << node.fi.fi << "," << node.fi.se << "}{" << node.se.fi << "," << node.se.se << "}";  
}

// bool checkon(iiii node, bool rem){
//     return ison[node.fi.fi][node.fi.se][node.se.fi][rem];
// }

// int getmemo(iiii node, bool rem){
//     return memo[node.fi.fi][node.fi.se][node.se.fi][rem];
// }

int dfs(iiii node, int rem){
    if (ison[node.fi.fi][node.fi.se][node.se.fi][rem] == 1){
        return memo[node.fi.fi][node.fi.se][node.se.fi][rem];
    }
    int ans = 0;
    // print(node); cout << endl;
    for (int i = 0; i < 4; i++){
        iiii D = d[i];
        iiii nu = node;
        nu.fi.fi += D.fi.fi;
        nu.fi.se += D.fi.se;
        nu.se.fi += D.se.fi;
        nu.se.se += D.se.se;
        // print(nu);
        int t = !isSame(nu);
        if (outGrid(nu)){
            // cout << "Out" << endl;
            continue;
        }
        if (isEnd(nu)){
            if (rem + t <= 1){
                // cout << "End and ok" << endl;
                ans++;
                continue;
            }
            // cout << "End but fuck" << endl;
            continue;
        }
        if (rem + t > 1){
            // cout << "too much:)))" << endl;
            continue;
        }
        // cout << "ok" << endl;
        ans += dfs(nu, rem + t);
    }
    ans %= mod;
    ison[node.fi.fi][node.fi.se][node.se.fi][rem] = 1;
    memo[node.fi.fi][node.fi.se][node.se.fi][rem] = ans;
    return ans;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> mod;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char x;
            cin >> x;
            a[i][j] = x - 'a';
        }
    }

    int x = dfs({{1,1},{n,m}}, (a[1][1] != a[n][m]));
    cout << x;
    return 0;
}