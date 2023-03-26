#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e3 + 10;

int n, m, k;
int s, t;
int a[maxN][maxN];
int two2one[maxN][maxN];
ii one2two[maxN];
int suoi[maxN * maxN];
priority_queue <ii, vector <ii>, greater <ii>> q;
int vis[maxN][maxN];
unordered_set <int> adj[maxN];

ii dir[]{
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};


bool check(int time){
    return 1;
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
                suoi[two2one[i][j]] = 1;
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
                adj[two2one[x][y]].insert(two2one[i][j]);
                adj[two2one[i][j]].insert(two2one[x][y]);
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

    if (abs(one2two[s].fi - one2two[t].fi) + abs(one2two[s].se - one2two[t].se) <= k - 2){
        cout << -1;
        return 0;
    }

    int left = 0;
    int right = 1e18;
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

    cout << ans;

    return 0;
}