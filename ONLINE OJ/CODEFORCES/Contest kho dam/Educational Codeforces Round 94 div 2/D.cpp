#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 3010;

int a[maxN];
int prefix[maxN][maxN];
int suffix[maxN][maxN];
int temp[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        // cout << "===TEST===" << endl;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            prefix[0][i] = 0;
            suffix[n + 1][i] = 0;
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                prefix[i][j] = prefix[i - 1][j] + (a[i] == j);
            }
        }
        for (int i = n; i >= 1; i--){
            for (int j = 1; j <= n; j++){
                suffix[i][j] = suffix[i + 1][j] + (a[i] == j);
            }
        }

        // for (int j = 1; j <= n; j++){
        //     for (int i = 1; i <= n; i++){
        //         cout << prefix[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for (int j = 1; j <= n; j++){
        //     for (int i = 1; i <= n; i++){
        //         cout << suffix[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int ans = 0;
        for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
                // cout << i << " " << j << " " << prefix[i - 1][a[j]] * suffix[j + 1][a[i]] << endl;
                ans += prefix[i - 1][a[j]] * suffix[j + 1][a[i]];
            }
        }

        cout << ans << endl;
    }
    return 0;
}