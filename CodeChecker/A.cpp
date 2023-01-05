#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 998244353;
const int maxN = 2e5 + 10;
int fact[maxN];


int add(int a, int b){
    return (a + b) % mod;
}
int subtr(int a, int b){
    return ((a + mod) - b) % mod; 
}
int mul(int a, int b){
    return (a * b) % mod;
}
void init(){
    fact[0] = 1;
    for (int i = 1; i < maxN; i++){
        fact[i] = mul(fact[i - 1], i);
    }
}
int fastpow(int n, int a){
    if (a == 1){
        return n;
    }
    int temp = fastpow(n, a / 2);
    int ans = mul(temp, temp);
    if (a % 2){
        return mul(ans, n);
    }
    else{
        return ans;
    }
}


int C(int n, int k){
   return mul(fact[n], fastpow(mul(fact[k], fact[n - k]), mod - 2));
}

vector <int> adj[maxN];
int dp[maxN];

void dfs(int node, int father){
    dp[node] = 1;
    int child = 0;
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        dfs(newNode,node);
        child++;
        dp[node] = mul(dp[node], dp[newNode]);
    }
    int now = 1;
    for (int i = 2; i <= child; i++){
        now = add(now, C(child,i));
    }
    dp[node] = mul(dp[node], now);
    // cout << "Node " << node << ": " << dp[node] << " " << now << endl;
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++){
        int x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    dfs(1,1);

    cout << dp[1];
    return 0;
}