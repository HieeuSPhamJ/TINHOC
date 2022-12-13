#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 7;

int a[4][maxN];
int can[maxN][4];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 0; i <= 1; i++){
            for (int j = 1; j <= n; j++){
                a[i][j] = 0;
                can[j][i] = 0;
                char x;
                cin >> x;
                if (x == 'B'){
                    a[i][j] = 1;
                }
            }
        }
        can[0][0] = 1;
        can[0][1] = 1;
        for (int i = 1; i <= n; i++){
            if (a[0][i] == a[1][i] and a[0][i] == 1){
                if (can[i - 1][0]){
                    can[i][1] = 1;
                }
                if (can[i - 1][1]){
                    can[i][0] = 1;
                }
            }
            else{
                if (a[0][i]){
                    if (can[i - 1][0]){
                        can[i][0] = 1;
                    }
                }
                if (a[1][i]){
                    if (can[i - 1][1]){
                        can[i][1] = 1;
                    }
                }
            }
        }
        int check = 1;

        for (int i = 1; i <= n; i++){
            if (can[i - 1][0] and can[i][1]){
                can[i][0] = 1;
            }
            if (can[i - 1][1] and can[i][0]){
                can[i][1] = 1;
            }
        }

        if (a[0][n] and can[n][0] == 0){
            check = 0;
        }
        
        if (a[1][n] and can[n][1] == 0){
            check = 0;
        }

        if (check){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}