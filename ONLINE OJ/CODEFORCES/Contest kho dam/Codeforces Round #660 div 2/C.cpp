#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

vector <int> adj[maxN];
int p[maxN];
int val[maxN];
ii dp[maxN];
int child[maxN];
int check = 1;

void findChild(int node, int father){
    child[node] = p[node];
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        findChild(newNode, node);
        child[node] += child[newNode];
    }
}

void DFS(int node, int father){
    int cnt = 0;
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        cnt++;
        DFS(newNode, node);
        dp[node].fi += dp[newNode].fi;
        dp[node].se += dp[newNode].se;
    }
    // cout << "Node: " << node << endl;
    // if (cnt == 0){
    //     if (val[node] > 0){
    //         dp[node] = {abs(val[node]), 0};
    //     }
    //     else{
    //         dp[node] = {0, abs(val[node])};
    //     }
    //     cout << "Leaf" << endl; 
    // }

    int sum = dp[node].fi + dp[node].se + p[node];
    // if (cnt){
    //     sum += p[node];
    // }
    // cout << "Child: " << child[node] << " " << sum << endl; 
    if (sum != child[node]){
        check = 0;
        // cout << "#" << endl;
    }
    int a = (sum - abs(val[node])) / 2;
    int b = sum - a;
    if (val[node] > 0){
        swap(a,b);
    }
    if (a < 0 or b < 0){
        check = 0;
    }
    if (a - b != val[node]){
        check = 0;
    }
    // cout << a << " " << b << endl;
    // cout << dp[node].fi << " " << dp[node].se << endl; 

    dp[node] = {a,b};
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
        int n, m;
        cin >> n >> m;
        check = 1;
        for (int i = 1; i <= n; i++){
            adj[i].clear();
            dp[i] = {0,0};
            cin >> p[i];
        }
        for (int i = 1; i <= n; i++){
            cin >> val[i];
        }
        for (int i = 1; i < n; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        findChild(1,1);
        // for (int i = 1; i <= n; i++){
        //     cout << child[i] << endl;
        // }
        DFS(1,1);
        if (check){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}