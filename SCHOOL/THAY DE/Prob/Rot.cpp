#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

char a[13][13];

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

    int k;
    cin >> k;
    k %= 360;
    if (k == 0){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];   
            }
        }
    }
    else if (k == 180){
        for (int i = n; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];   
            }
        }
    }
    return 0;
}