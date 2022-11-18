#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

void MAIN(){
    int n, m, k;
    cin >> n >> m >> k;
    int a[n + 3][m + 3] = {0};
    int prefix[n + 3][m + 3] = {0};
    for (int i = 0; i <= n; i++){
    for (int j = 0; j <= m; j++){
        prefix[i][j] = 0;
        // cout << prefix[i][j] << " ";
    }
    // cout << endl;
    }
    for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
        char x;
        cin >> x;
        a[i][j] = x - 'A';
        prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j];
        // cout << prefix[i][j] << " ";
    }
    // cout << endl;
    }

    
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int _i = n; _i >= i; _i--){
                for (int _j = m; _j >= j; _j--){
                    int area = (abs(i - _i) + 1) * (abs(j - _j) + 1);
                    if (area <= ans){
                        goto brubru;
                    }
                    int B = prefix[_i][_j] - prefix[_i][j - 1] - prefix[i - 1][_j] + prefix[i - 1][j - 1];
                    int A = area - B;
                    // cout << i << " " << j << " " << _i << " " << _j << endl;
                    // cout << A << " " << B << endl;
                    if (abs(A - B) <= k){
                        ans = max(ans,area);
                    }
                }   
                brubru:;
            }
        }   
    }

    cout << ans << endl;

}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        MAIN();
    }
    return 0;
}