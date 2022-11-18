#pragma GCC optimize("O2")
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define query pair <pair <ii,ii>,int>
#define int long long
#define double long double
#define x1 fi.fi.fi
#define y1 fi.fi.se
#define x2 fi.se.fi
#define y2 fi.se.se
#define val se
#define matrix vector<vector<int>>
#define endl '\n'
using namespace std;


int tempPre[1000010];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int a[n + 3][m + 3] = {0};
    int grid[n + 3][m + 3] = {0};
    int maxtop[n + 3][m + 3] = {0};
    int maxdown[n + 3][m + 3] = {0};
    int prefix[n + 3][m + 3] = {0};

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    int test;
    cin >> test;
    vector <query> Q;
    while(test--){
        int xx1,yy1,xx2,yy2,val;
        cin >> xx1 >> yy1 >> xx2 >> yy2 >> val;
        Q.push_back({{{xx1,yy1},{xx2,yy2}},val});
        prefix[xx1][yy1] += val;
        prefix[xx2 + 1][yy2 + 1] += val;
        prefix[xx1][yy2 + 1] -= val;
        prefix[xx2 + 1][yy1] -= val;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            tempPre[j] += prefix[i][j];
        }
        int temp = 0;
        for (int j = 1; j <= m; j++){
            temp += tempPre[j];
            grid[i][j] = a[i][j] + temp;
        }
    }
    int maxVal = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            maxtop[i][j] = max({grid[i][j], maxtop[i - 1][j], maxtop[i][j - 1]});
            maxVal = max(maxVal, grid[i][j]);
        }
    }
    for (int i = n; i >= 1; i--){
        for (int j = m; j >= 1; j--){
            maxdown[i][j] = max({grid[i][j], maxdown[i + 1][j], maxdown[i][j + 1]});
        }
    }   
    int ans = 1e18;
    for (int i = 0; i < Q.size(); i++){
        query q = Q[i];
        int xx1 = q.x1, yy1 = q.y1, xx2 = q.x2, yy2 = q.y2, val = q.val;
        int maxOut = maxtop[xx1 - 1][m];
        maxOut = max(maxOut, maxtop[n][yy1 - 1]);
        maxOut = max(maxOut, maxdown[xx2 + 1][1]);
        maxOut = max(maxOut, maxdown[1][yy2 + 1]);
        ans = min(ans, max(maxOut, maxVal - val));
    }
    cout << ans;
    return 0;
}
