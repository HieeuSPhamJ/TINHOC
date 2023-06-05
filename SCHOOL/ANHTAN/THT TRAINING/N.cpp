#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int x, y, u, v;
int res = 1e18;
int ans = 0;

int a[10][10];
ii d[]{
    {-2,2},
    {2,-2},
    {2,2},
    {-2,-2}
};

void backtracking(int i, int j){
    if (i < 1 or i > 8 or j < 1 or j > 8){
        return;
    }
    // cout << i << " " << j << endl;
    if (i == u and j == v){
        res = min(res,ans);
        return;
    }
    a[i][j] = 1;
    for (int di = 0; di < 4; di++){
        int xx = i + d[di].fi;
        int yy = j + d[di].se;
        if (a[xx][yy] == 0){
        ans++;
        backtracking(xx,yy);
        ans--;
        }
    }
    a[i][j] = 0;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> x >> y >> u >> v;
    backtracking(x, y);
    if (res == 1e18){
        cout << -1 << endl;
        return 0;
    }
    cout << res << endl;
    return 0;
}