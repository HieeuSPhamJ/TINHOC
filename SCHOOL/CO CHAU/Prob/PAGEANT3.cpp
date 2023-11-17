#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int n, m;
int a[100][100];
int grid[100][100];
ii d[] = {
    {1,0},
    {0,1},
    {-1,0},
    {0,-1}
};
ii dis[6];
int visited[100][100];
int onlydis[6];
int type = 0;
int cntLim = 0;

void mark(int i, int j){
    // cout << i << " " << j << " " << type << endl;
    grid[i][j] = type;
    for (int x = 0; x <= 3; x++){
        int newi = i + d[x].fi;
        int newj = j + d[x].se;
        if (newi >= 1 and newi <= n and newj >= 1 and newj <= m and grid[newi][newj] == 0 and a[newi][newj] == 1){
            mark(newi, newj);
        }
    }
}


signed main(){
    // freopen("Pageant3.INP", "r", stdin);
    // freopen("Pageant3.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char inp;
            cin >> inp;
            if (inp == 'X'){
                a[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i][j] and grid[i][j] == 0){
                type++;
                mark(i,j);
                dis[type] = {i,j};
            }
        }
    }

    onlydis[1] = onlydis[2] = onlydis[3] = 1e18;

    vector <ii> lists[4];

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << grid[i][j] << " ";
            lists[grid[i][j]].push_back({i,j});
        }
        cout << endl;
    }

    for (int t = 1; t <= 3; t++){
        for (auto i: lists[t]){
            int tt = t + 1;
            if (tt == 4){
                tt = 1;
            }
            for (auto j: lists[tt]){
                onlydis[t] = min(onlydis[t], abs(i.fi - j.fi) + abs(i.se - j.se) - 1);                
            }
        }
    }

    // for (int i = 1; i <= 3; i++){
    //     cout << onlydis[i] << endl;
    // }

    sort(onlydis + 1, onlydis + 4);

    int ans = onlydis[1] + onlydis[2];

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (grid[i][j]){
                continue;
            }
            int temp = 0;
            for (int t = 1; t <= 3; t++){
                int temptemp = 1e18;
                for (auto x: lists[t]){
                    temptemp = min(temptemp, abs(i - x.fi) + abs(j - x.se) - 1);
                }
                temp += temptemp;
            }
            ans = min(ans, temp + 1);
        }
    }

    cout << ans;


    return 0;
}