#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;
const int mod = 998244353;
int sum[maxN][4];
int way[maxN][4];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    way[0][3] = 1;
    for (int i = 0; i <= n; i++){
        for (int mask = 0; mask < 4; mask++){
            int &w = way[i][mask];
            int &s = sum[i][mask];
            w %= mod;
            s %= mod;
            if (mask == 0){
                way[i + 1][0] += w;
                sum[i + 1][0] += s;

                way[i + 1][1] += w;
                sum[i + 1][1] += s + w * 3;

                way[i + 1][2] += w;
                sum[i + 1][2] += s + w * 3;

                way[i + 1][3] += 2 * w;
                sum[i + 1][3] += 2 * (s + w * 3);
            }
            else if (mask == 1 or mask == 2){
                way[i + 1][0] += w;
                sum[i + 1][0] += s;

                way[i + 1][3] += w;
                sum[i + 1][3] += s + w * 3;
            }
            else{
                way[i + 1][0] += w;
                sum[i + 1][0] += s;
            }
        }
    }
    // for (int j = 0; j < 4; j++){
    //     for (int i = 1; i <= n; i++){
    //         cout << way[i][j] << " ";
    //     }   
    //     cout << endl;
    // }
    cout << (sum[n][0] + sum[n][1] + sum[n][2] + sum[n][3]) % mod << endl;
    return 0;
}

/*

*/