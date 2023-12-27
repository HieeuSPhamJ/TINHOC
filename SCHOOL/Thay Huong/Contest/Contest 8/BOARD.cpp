#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int a[110][110];
int b[110][110];

void change(int x, int y){
    a[x][y] = !a[x][y];
    a[x + 1][y] = !a[x + 1][y];
    a[x][y + 1] = !a[x][y + 1];
    a[x + 1][y + 1] = !a[x + 1][y + 1];
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("BOARD.inp", "r")) {
        freopen("BOARD.inp", "r", stdin);
        freopen("BOARD.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char c;
            cin >> c;
            a[i][j] = (c == 'B');
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char c;
            cin >> c;
            b[i][j] = (c == 'B');
        }
    }
    vector <ii> ls;
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            if (a[i][j] != b[i][j]){
                ls.push_back({i,j});
                change(i,j);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] != b[i][j]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    cout << (int)ls.size() << endl;
    for (auto i: ls){
        cout << i.fi << " " << i.se << endl;
    }
    return 0;
}