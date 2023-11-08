#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 5010;

vector <int> adj[maxN];
vector <int> dp[maxN][2];
int c[maxN];
int d[maxN];

void cal(vector <int> &a, vector <int> &b){
    vector <int> c(a.size() + b.size() - 1, (int)1e18);
    for (int i = 0; i < (int)a.size(); i++) {
		for (int j = 0; j < (int)b.size(); j++) {
			c[i + j] = min(c[i + j], a[i] + b[j]);
		}
	}
    swap(a,c);
}

void dfs(int nu){
    dp[nu][0] = {0, c[nu]};
	dp[nu][1] = {(int)1e18, d[nu]};
	for (int i: adj[nu]) {
		dfs(i);
		cal(dp[nu][0], dp[i][0]);
		cal(dp[nu][1], dp[i][1]);
	}
	for (int i = 0; i < (int)dp[nu][1].size(); i++) {
		dp[nu][1][i] = min(dp[nu][1][i], dp[nu][0][i]);
	}
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("shopping.inp", "r")) {
        freopen("shopping.inp", "r", stdin);
        freopen("shopping.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    cin >> c[1] >> d[1];
    d[1] = c[1] - d[1];
    for (int i = 2; i <= n; i++){
        int p;
        cin >> c[i] >> d[i] >> p;
        d[i] = c[i] - d[i];
        adj[p].push_back(i); 
        // cout << p  << " " << i << endl;
    }
    dfs(1);
    int res = 0;
    for (int i = 0; i < (int)dp[1][1].size(); i++){
        if (dp[1][1][i] <= m){
            res = i;
        }
    }
    cout << res << endl;
    return 0;
}