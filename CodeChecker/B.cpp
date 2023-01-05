#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const int MOD = 998244353;

vector<int> T[N];
int dp[N][3];
int f[3];
int nw[3];
int mult(int x, int y){
    return (x * 1ll * y) % MOD;
}

int add(int x, int y){
    x += y;
    if(x >= MOD) x -= MOD;
    else if(x < 0) x += MOD;
    return x;
}

void dfs(int node){
    for(auto x : T[node]){
        dfs(x);
    }
    if(T[node].size() == 0){
        dp[node][0] = 1;
    }
    else{
        dp[node][2] = 1;
        for(auto x : T[node]){
            dp[node][2] = mult(dp[node][2], add(dp[x][0], dp[x][2]));
        }
        for(int p = 0 ; p < 3; p ++ ) f[p]=0;
        f[0]=1;
        int j;
        for(auto x : T[node]){
            nw[0] = nw[1] = nw[2] = 0;
            for(int i = 0 ; i < 3; i ++ ){
                nw[i] = add(nw[i], mult(f[i], add(dp[x][0], dp[x][2])));
                j = min(i + 1, 2);
                nw[j] = add(nw[j], mult(f[i], add(dp[x][0], dp[x][1])));
            }
            for(int i = 0 ; i < 3; i ++ ){
                f[i] = nw[i];
            }
        }
        dp[node][1] = f[1];
        dp[node][0] = f[2];
    }
}

int main(){
    fastIO;
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    int p;
    for(int i = 2; i <= n; i ++ ){
        cin >> p;
        T[p].push_back(i);
    }
    dfs(1);
    cout << add(dp[1][0], dp[1][2]) << "\n";
    return 0;
}
