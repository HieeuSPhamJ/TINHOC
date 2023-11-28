#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2010;

int a[maxN][maxN];
int vis[maxN][maxN];
ii d[] = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= m + 1; j++){
            a[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    queue <ii> q;
    if (a[x][y] == 0){
        q.push({x,y});
        vis[x][y] = 1;
    }

    while(!q.empty()){
        ii t = q.front();
        q.pop();
        for (int di = 0; di < 4; di++){
            ii nu = t;
            nu.fi += d[di].fi;
            nu.se += d[di].se;
            if (a[nu.fi][nu.se] == 0 and vis[nu.fi][nu.se] == 0){
                vis[nu.fi][nu.se] = 1;
                q.push(nu);
            }
        }
    }

    int res = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            res += vis[i][j];
        }
    } 
    
    cout << res << endl;

    return 0;
}