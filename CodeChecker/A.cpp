#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define LINE "---------------\n"
#define sz(a) (int)a.size()
using namespace std;
using PII = pair <int, int>;
const int N = 802;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int n, m, X1, Y1, X2, Y2;
vector <PII> hives;
int mat[N][N], maze[N][N];
bool check(int lim) {
    memcpy(maze, mat, sizeof(mat));
    queue <PII> bfs1, bfs2;
    for (auto& [a, b] : hives) bfs2.push({a, b});
    for (int i = 0; i < lim; i++) {
        int rep = sz(bfs2);
        for (int j = 0; j < rep; j++) {
            int x, y; tie(x, y) = bfs2.front(); bfs2.pop();
            for (int a = 0; a < 4; a++) {
                int xx = dx[a] + x;
                int yy = dy[a] + y;
                if (xx < 1 || xx > n || yy < 1 || yy > n || maze[xx][yy] != 0) continue;
                maze[xx][yy] = 1;
                bfs2.push({xx, yy});
            }
        }
    }
    if (maze[X1][Y1] == 1) return 0;
    maze[X1][Y1] = 2;
    bfs1.push({X1, Y1});
    bool changed = 1;
    // cout << "START\n";
    // cout << lim << '\n';
    // for (int i = 1; i <= n; i++)
    // for (int j = 1; j <= n; j++) cout << maze[i][j] << " \n"[j==n];
            
 
    while (maze[X2][Y2] == 4 && changed) {
        // move bear
        changed = 0;
        for (int i = 0; i < m; i++) {
            int rep = sz(bfs1);
            for (int j = 0; j < rep; j++) {
                int x, y; tie(x, y) = bfs1.front(); bfs1.pop();
                if (maze[x][y] == 1) continue;
                for (int a = 0; a < 4; a++) {
                    int xx = dx[a] + x;
                    int yy = dy[a] + y;
                    if (xx < 1 || xx > n || yy < 1 || yy > n || maze[xx][yy] == 1 || maze[xx][yy] == 2) continue;
                    changed = 1;
                    maze[xx][yy] = 2;
                    bfs1.push({xx, yy});
                }
            }
        }
        if (maze[X2][Y2] != 4) return 1;
        // spread bees
        int rep = sz(bfs2);
        for (int j = 0; j < rep; j++) {
            int x, y; tie(x, y) = bfs2.front(); bfs2.pop();
            for (int a = 0; a < 4; a++) {
                int xx = dx[a] + x;
                int yy = dy[a] + y;
                if (xx < 1 || xx > n || yy < 1 || yy > n || maze[xx][yy] == 1 || maze[xx][yy] == 4) continue;
 
                changed = 1;
                maze[xx][yy] = 1;
                bfs2.push({xx, yy});
            }
        }
        // cout << LINE;
        // for (int i = 1; i <= n; i++)
        // for (int j = 1; j <= n; j++) cout << maze[i][j] << " \n"[j==n];
                
    }
    return 0;
}
signed main() {
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout); 
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("0.in", "r", stdin);
    // freopen("0.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
        char x; cin >> x;
        if (x == 'T') { // tree
            mat[i][j] = 1;
        } else if (x == 'G') { // grass
            mat[i][j] = 0;
        } else if (x == 'M') { // mecho the bear
            tie(X1, Y1) = mp(i, j);
            mat[i][j] = 0;
        } else if (x == 'D') { // home of the mecho
            mat[i][j] = 4;
            tie(X2, Y2) = mp(i, j);
        } else if (x == 'H') { // bee hive
            mat[i][j] = 1;
            hives.pb({i, j});
        }
    }
    int l = 0, r = n*n/2, ans = -1;
    while (l <= r) {
        int m = (l+r)>>1;
        if (check(m)) {
            l = m+1;
            ans = m;
        } else {
            r = m-1;
        }
    }
    cout << ans << "\n";
}