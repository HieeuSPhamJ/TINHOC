#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define iii pair <int,ii>
using namespace std;


// const int maxN = 507;
// const int inf = 1e18;

// int n, m;
// int a[7][maxN];
// int visited[7][maxN];
// ii d[]{
//     {0, 1},
//     {1, 0},
//     {0, -1},
//     {-1, 0}
// };

// void init(){
//     for (int i = 1; i <= n; i++){
//         for (int j = 1; j <= m; j++){
//             visited[i][j] = inf;
//         }
//     }
// }

// bool check(ii node){
//     if (node.fi >= 1 and node.fi <= n and node.se >= 1 and node.se <= m){
//         return 1;
//     }
//     return 0;
// }

// void dickcha(ii s){
//     priority_queue <iii, vector <iii>, greater <iii>> q;
//     visited[s.fi][s.se] = a[s.fi][s.se];
//     q.push({visited[s.fi][s.se], s});
//     while(!q.empty()){
//         iii t = q.top();
//         q.pop();
//         for (int i = 0; i < 4; i++){
//             ii nu = t.se;
//             nu.fi += d[i].fi;
//             nu.se += d[i].se;
//             if (check(nu) and visited[nu.fi][nu.se] > t.fi + a[nu.fi][nu.se]){
//                 visited[nu.fi][nu.se] = t.fi + a[nu.fi][nu.se];
//                 q.push({visited[nu.fi][nu.se], nu});
//             }
//         }
//     }
// }

signed main(){
    freopen("PATH.INP", "r", stdin);
    freopen("PATH.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cin >> n >> m;
    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= m; j++){
    //         cin >> a[i][j];
    //     }
    // }
    
    // int test;
    // cin >> test;
    // while(test--){
    //     int x, y;
    //     cin >> x >> y;
    //     int u, v;
    //     cin >> u >> v;
    //     // init();
    //     // dickcha({x,y});
    //     cout << visited[u][v] << endl;
    // }

    return 0;
}