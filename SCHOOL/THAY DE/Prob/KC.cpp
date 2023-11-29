#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 256;

int pre[257][257][257];

signed main(){
    // freopen("KC.INP", "r", stdin);
    // freopen("KC.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int m;
    cin >> m;
    int mX = 1;
    int mY = 1;
    int mZ = 1;

    for (int i = 1; i <= n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        x++;
        y++;
        z++;
        mX = max(mX,x);
        mY = max(mY,y);
        mZ = max(mZ,z);
        
        pre[x][y][z]++;
    }
    for (int i = 1; i <= mX; i++){
        for (int j = 1; j <= mY; j++){
            for (int k = 1; k <= mZ; k++){
                pre[i][j][k] = pre[i][j][k] + pre[i - 1][j][k] + pre[i][j - 1][k] + pre[i][j][k - 1]
                    - (pre[i - 1][j - 1][k] + pre[i][j - 1][k - 1] + pre[i - 1][j][k - 1])
                    + pre[i - 1][j - 1][k - 1];
                // cout << i << " " << j << " " << k << ": " << pre[i][j][k] << endl;
                // cout << " " << pre[i - 1][j][k] + pre[i][j - 1][k] + pre[i][j][k - 1] << endl;
                // cout << " " << (pre[i - 1][j - 1][k] + pre[i][j - 1][k - 1] + pre[i - 1][j][k - 1]) << endl;
                // cout << " " << pre[i - 1][j - 1][k - 1] << endl;
            }
        }
    }
    // cout << pre[2][2][2] << endl;
    int res = 1e9;
    int sq = pow(m,1/3);
    for (int i = 1; i <= mX; i++){
        for (int j = 1; j <= mY; j++){
            for (int k = 1; k <= mZ; k++){
                int l = sq;
                int r = min(res - 1, min({i,j,k}) - 1);
                int ans = 1e9;
                while(l <= r){
                    int mid = (l + r) / 2;
                    int i0 = i - mid;
                    int j0 = j - mid;
                    int k0 = k - mid;
                    int sum = pre[i][j][k];
                    sum = sum - (pre[i0 - 1][j][k] + pre[i][j0 - 1][k] + pre[i][j][k0 - 1])
                        + (pre[i0 - 1][j0 - 1][k] + pre[i][j0 - 1][k0 - 1] + pre[i0 - 1][j][k0 - 1])
                        - pre[i0 - 1][j0 - 1][k0 - 1];
                    // cout << i << " " << j << " " << k << ": " << sum << endl;
                    if (sum >= m){
                        ans = mid;
                        r = mid - 1;
                    }
                    else{
                        l = mid + 1;
                    }
                }
                res = min(res,ans);
            }
        }
    }
    cout << res << endl;
    return 0;
}