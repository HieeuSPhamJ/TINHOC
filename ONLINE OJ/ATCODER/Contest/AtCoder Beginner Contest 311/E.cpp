#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 3e3 + 10;

int pre[maxN][maxN];
int grid[maxN][maxN];

int cal(int i, int j, int n){
    int sum = pre[i + n - 1][j + n - 1];
    // cout << sum << endl;
    sum = sum - (pre[i + n - 1][j - 1] + pre[i - 1][j + n - 1]);
    sum += pre[i - 1][j - 1];
    return sum;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++){
        int a, b;
        cin >> a >> b;
        grid[a][b] = 1;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + grid[i][j]; 
            // cout << grid[i][j] << " ";
        }
        // cout << endl;
    }

    int res = 0;

    // cout << cal(2,2,2) << endl;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (grid[i][j]){
                continue;
            }
            int l = 1;
            int r = min(n - i + 1, m - j + 1);
            int tres = 0;
            while(l <= r){
                int mid = (l + r) / 2;
                if (cal(i,j,mid)){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                    tres = mid;
                }
            }
            // cout << i << " " << j << " " << tres << endl;
            res += tres;
        }
    }

    cout << res << endl;

    return 0;
}