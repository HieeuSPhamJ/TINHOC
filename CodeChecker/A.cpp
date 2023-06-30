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
      freopen("input.inp", "r", stdin);
      freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int x, k, n;
        cin >> n >> k >> x;
        if (x != 1){
            cout << "YES" << endl;
            // cout << n << endl;
            // for (int i = 1; i <= n; i++){
            //     cout << 1 << " ";
            // }
            // cout << endl;
        }
        else{
            if (n == 1){
                cout << "NO" << endl;
            }
            else{
                if (k >= 2 + n % 2){
                    cout << "YES" << endl;
                    // cout << n / 2 << endl;
                    // if (n % 2){
                    //     cout << 3 << " ";
                    //     n -= 3;
                    // }
                    // while(n){
                    //     cout << 2 << " ";
                    //     n -= 2;
                    // }
                    // cout << endl;
                }
                else {
                    int ok = 0;
                    for (int i = 1; i <= k; i++){
                        if (i != x and n % i != x){
                            ok = 1;
                        }
                    }
                    if (ok == 0){
                        cout << "NO" << endl;
                    }
                }
            }
        }
    }
    return 0;
}