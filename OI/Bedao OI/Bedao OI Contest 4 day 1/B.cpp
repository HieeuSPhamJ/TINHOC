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

int a[100][100];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 100;
    // for (int i = 0; i <= n; i++){
    //     a[i][0] = 1;
    //     a[i][i] = 1;
    // }
    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j < i; j++){
    //         a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    //     }
    // }
    // for (int i = 0; i <= n; i++){
    //     for (int j = 0; j <= n - i; j++){
    //         cout << " ";
    //     }
    //     for (int j = 0; j <= i; j++){
    //         if (a[i][j] % 2){
    //             cout << "#" << " ";
    //         }
    //         else{
    //             cout << "." << " ";
    //         }
    //         // cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 0; i <= n; i++){
    //     cout << i << ": ";
    //     for (int j = 0; j <= i; j++){
    //         if (a[i][j] % 2 == 0){
    //             cout << j << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    for (int i = 1, pre = 0; i <= n; i++){
        int x = i;
        while(x % 2){
            pre++;
            x /= 2;
        }
        cout << pre << " ";
    }
    return 0;
}