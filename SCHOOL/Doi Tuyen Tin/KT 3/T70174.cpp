#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

vector <int> adj[maxN];
ii a[maxN];
int dp[maxN];
int child[maxN];

int LCM(int x, int y){
    return x * y /__gcd(x,y);
}

void dfs(int can){
    int t1 = 0;
    int t2 = 0;
    int s1 = 0;
    int s2 = 0;
    if (a[can].fi < 0){
        t1 = -a[can].fi;
        s1 = 1;
    }
    else{
        dfs(a[can].fi);
        t1 = dp[a[can].fi];
        s1 = child[a[can].fi];
    }
    if (a[can].se < 0){
        t2 = -a[can].se;
        s2 = 1;
    }
    else{
        dfs(a[can].se);
        t2 = dp[a[can].se];
        s2 = child[a[can].se];
    }

    child[can] = s1 + s2;
    dp[can] = t1 + t2 + LCM(t1,t2);
    
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int dia = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }

    dfs(1,1);

    cout << dp[1] << endl;

    return 0;
}