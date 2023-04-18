#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e3 + 10;

int n, m, k;
int s, t;
int a[maxN][maxN];
int two2one[maxN][maxN];
ii one2two[maxN * maxN];
int vis[maxN * maxN];
vector <int> adj[maxN * maxN];
int grid[maxN * maxN];
vector <int> suoi;

ii dir[]{
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};


bool check(int time){
    // cout << "NOW: " << time << endl;
    

    for (int i = 1; i <= n; i++){
        vis[i] = 1e9;
    }

    deque <ii> q;
    q.push_back({0, s});
    vis[s] = 0;

    while(q.size()){
        ii te = q.front();
        q.pop_front();
        if (vis[te.se] != te.fi){
            continue;
        }
        for (auto nu: adj[te.se]){
            if (vis[nu] > vis[te.se] + (grid[nu] <= time)){
                vis[nu] = vis[te.se] + (grid[nu] <= time);
                if (nu == t and vis[t] <= k){
                    return 1;
                }
                if (vis[nu] != vis[te.se]){
                    q.push_back({vis[nu],nu});
                }
                else{
                    q.push_front({vis[nu],nu});
                }
            }
        }
    }
    // for (int i = 1; i <= n / m; i++){
    //     for (int j = 1; j <= m; j++){
    //         cout << vis[two2one[i][j]] << " ";
    //     }
    //     cout << endl;
    // }
    return vis[t] <= k;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1, cnt = 0; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cnt++;
            two2one[i][j] = cnt;
            one2two[cnt] = {i,j};
            char x;
            cin >> x;
            if (x == 'H'){
                s = two2one[i][j];
            }
            if (x == 'G'){
                t = two2one[i][j];
            }
            if (x == 'S'){
                a[i][j] = 1;
                suoi.push_back(two2one[i][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int d = 0; d < 4; d++){
                int x = i + dir[d].fi;
                int y = j + dir[d].se;
                if (x <= 0 or y <= 0 or x > n or y > m){
                    continue;
                }
                adj[two2one[x][y]].push_back(two2one[i][j]);
                adj[two2one[i][j]].push_back(two2one[x][y]);
            }
        }
    }
    n *= m;

    // for (int i = 1; i <= n; i++){
    //     cout << i << ": ";
    //     for (auto j: adj[i]){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }



    queue <int> q;
    for (auto i: suoi){
        q.push(i);
        grid[i] = 1;
    }
    while(q.size()){
        int te = q.front();
        q.pop();
        // cout << t << endl;
        for (auto i: adj[te]){
            if (grid[i] == 0){
                grid[i] = grid[te] + 1;
                q.push(i);
                // cout << i << " ";
            }
        }
        // cout << endl;
    }

    grid[s] = 1e9;
    grid[t] = 1e9;

    // for (int i = 1; i <= n / m; i++){
    //     for (int j = 1; j <= m; j++){
    //         cout << grid[two2one[i][j]] << " ";
    //     }
    //     cout << endl;
    // }
    
    int left = 0;
    int right = 1e3 * 2;
    int ans = 0;

    while(left <= right){
        int mid = (left + right) / 2;
        if (check(mid)){
            left = mid + 1;
            ans = mid;
        }
        else{
            right = mid - 1;
        }
    }

    if (ans == 1e3 * 2){
        cout << -1;
        return 0;
    }
    // if (n/m == 5 and m == 5){
    //     cout << 5 << endl;
    //     return 0;
    // }
    cout << ans;

    return 0;
}