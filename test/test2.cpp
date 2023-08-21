#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

vector <int> adj[maxN];
int vis;
int dp[maxN];

void bfs(int nu, int fa){
    vis++;
    dp[nu] = 1;
    vector <int> ls;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        bfs(i,nu);
        dp[nu] = max(dp[nu], dp[i] + 1);
        ls.push_back(dp[i]);
    }
    if (ls.size() == 1){
        if (ls.front() != 1){
            vis = 1e18;
        }
    }
    if (ls.size() == 2){
        if (abs(ls.back() - ls.front()) > 1){
            vis = 1e18;
        }
    }
}


signed main(){
    freopen("nhap2.txt", "r", stdin);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1 ; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1,1);
    cout << vis << " " << n << endl;
    return 0;
}