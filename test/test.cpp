#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define iii pair<int,ii>
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1010;
const int inf = 1e18;

int n, m, sx, sy, tx, ty;
int k;

int grid[maxN][maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> sx >> sy >> tx >> ty;
    cin >> k;
    int fv = 1e18;
    for (int i = 1; i <= k; i++){
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
    }

    for (int i = m; i >= 1; i--){
        for (int j = 1; j <= n; j++){
            if (grid[j][i]){
                cout << "O" << " ";
            }
            else{
                cout << "+" << " ";
            }
        }
        cout << endl;
    }


    return 0;
} 