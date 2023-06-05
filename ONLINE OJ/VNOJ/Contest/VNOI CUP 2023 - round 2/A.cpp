#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

char a[510][510];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }


    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            if (a[i][j] != a[i + 1][j] and a[i][j] != a[i][j + 1] and a[i + 1][j] != a[i + 1][j + 1] and a[i][j + 1] == a[i + 1][j + 1]){
                cout << "YES" << endl;
                return 0;
            }
        }   
    }

    cout << "NO" << endl;
    return 0;
}