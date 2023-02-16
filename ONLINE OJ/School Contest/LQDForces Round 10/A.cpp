#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, m, h, w;
        cin >> n >> m >> h >> w;
        vector <vector <int>> a;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++){
            a[i].resize(m + 1);
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        int ok = 1;
        // cout << "Hang: " << endl;
        for (int i = 1; i <= n; i++){
            int last = 0;
            // cout << "with " << i << endl;
            for (int j = 1; j <= m; j++){
                if (a[i][j]){
                    // cout << j << " " << last << endl;
                    if (j - last - 1 < w and j - last - 1 > 0){
                        ok = 0;
                        // cout << "*";
                    }
                    last = j;
                }
            }
            if (m - last < w and m - last > 0){
                ok = 0;
            }
        }
        
        // cout << "Cot: " << endl;
        for (int j = 1; j <= m; j++){
            int last = 0;
            // cout << "with " << j << endl;
            for (int i = 1; i <= n; i++){
                if (a[i][j]){
                    // cout << i << " " << last << endl;
                    if (i - last - 1 < h and i - last - 1 > 0){
                        ok = 0;
                        // cout << "*" << endl;
                    }
                    last = i;
                }
            }
            if (n - last < h and n - last > 0){
                ok = 0;
            }
        }

        if (ok){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}