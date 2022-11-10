#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

char a[200][200];
vector <int> goal[200][200];

ii d[] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};

int n, m;
int visited[200][200];

bool check(ii nuuuuu){
    int x = nuuuuu.fi;
    int y = nuuuuu.se;
    if(1 <= x and x <= n and 1 <= y and y <= m){
        return 1;
    }
    return 0;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'U'){
            x--;
        }
        else if (s[i] == 'D'){
            x++;
        }
        if (s[i] == 'R'){
            y++;
        }
        else if (s[i] == 'L'){
            y--;
        }
        goal[x][y].push_back(i + 1);
    }
    int u,v;
    cin >> u >> v;
    if (u == x and v == y){
        cout << 0;
        return 0;
    }
    queue <ii> Q;
    Q.push({u,v});
    visited[u][v] = 1;
    while(!Q.empty()){
        ii t = Q.front();
        Q.pop();
        // cout << "Temp: " << t.fi << " " << t.se << endl;
        for (int i = 0; i < 4; i++){
            ii nude;
            nude.fi = t.fi + d[i].fi;
            nude.se = t.se + d[i].se;
            if (check(nude) and visited[nude.fi][nude.se] == 0 and a[nude.fi][nude.se] == '0'){
                // cout << nude.fi << " " << nude.se << endl;
                visited[nude.fi][nude.se] = visited[t.fi][t.se] + 1;
                Q.push(nude);
            }
        }
    }

    int ans = 1e18;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            visited[i][j]--;
            if (visited[i][j] == -1){
                visited[i][j] = 1e18;
            }
            for (auto g: goal[i][j]){
                if (visited[i][j] <= g and g != 0){
                    if ((g - visited[i][j]) % 2 == 0){
                        // cout << i << " " << j << endl;
                        ans = min(ans, g);
                    }
                }
            }
        }
    }

    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= m; j++){
    //         cout << goal[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= m; j++){
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if (ans == 1e18){
        cout << -1;
    }
    else{
        cout << ans;
    }
    
    return 0;
}