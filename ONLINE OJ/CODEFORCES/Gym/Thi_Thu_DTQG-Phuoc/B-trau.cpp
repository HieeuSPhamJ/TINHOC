#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int a[4][100000];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int j = 1; j <= 3; j++){
        for (int i = 1; i <= n; i++){
            cin >> a[j][i];
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                if (a[1][i] * a[2][j] * a[3][k] == m){
                    res++;
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}