#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

int a[510][510];

int cal(int i, int j){
    return a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
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
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                char inp;
                cin >> inp;
                if (inp == '1'){
                    a[i][j] = 1;
                }
                else{
                    a[i][j] = 0;
                }
            }
        }
        
        int ans = 0;
        int check = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                ans += a[i][j];
                if (a[i][j] == 0){
                    check = 1;
                }
                // cout << a[i][j];
            }
            // cout << endl;
        }
        
        ans -= 2;

        if (check != 0){
            ans++;
        }

        int br = 0;

        for (int i = 1; br == 0 and i < n; i++){
            for (int j = 1; br == 0 and j < m; j++){
                if(cal(i,j) <= 2){
                    ans++;
                    br = 1;
                    break;
                }
            }
        }

        cout << ans << endl;



        
    }
    return 0;
}