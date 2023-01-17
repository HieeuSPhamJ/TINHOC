#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 5010;

int a[maxN];
bool Left[maxN][maxN];
bool Right[maxN][maxN];
int prefix[maxN][maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int maxV = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        maxV = max(maxV, a[i]);
    }

    Left[0][0] = 1;
    for (int j = 0; j <= k; j++){
        prefix[0][j] = 1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= k; j++){
            if (Left[i - 1][j]){
                Left[i][j] = 1;
                if (j + a[i] <= k){
                    Left[i][j + a[i]] = 1;
                }
            }
        }
        prefix[i][0] = 1;
        for (int j = 1; j <= k; j++){
            prefix[i][j] = prefix[i][j - 1] + Left[i][j];
        }
    }
    Right[n + 1][0] = 1;
    for (int i = n; i >= 1; i--){
        // cout << i << ": " << endl;
        for (int j = 0; j <= k; j++){
            if (Right[i + 1][j]){
                // cout << j << " " << j + a[i] << endl;
                Right[i][j] = 1;
                if (j + a[i] <= k){
                    Right[i][j + a[i]] = 1;
                }
            }
        }
        cout << endl;
    }

    // for (int i = 0; i <= n; i++){
    //     for (int j = 0; j <= k; j++){
    //         cout << Left[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int ans = 0;

    for (int i = 1; i <= n; i++){
        int hi = k - 1;
        int lo = k - a[i];
        int ok = 1;
        // cout << "With: " << i << " " << a[i] << endl;
        for (int j = 0; j <= k; j++){
            if (hi - j >= 0 and Right[i + 1][j]){
                int cnt = prefix[i - 1][hi - j];
                if (lo - j > 0){
                    cnt -= prefix[i - 1][lo - j - 1];
                }
                // cout << j << " [" << max(lo - j, 0ll) << ", " << hi - j << "]" << endl;
                if (cnt > 0){
                    ok = 0;
                    // cout << "*" << endl;
                }
            }
        }
        if (ok){
            // cout << i << endl;
            ans++;
        }
    }

    cout << ans;
    return 0;
}