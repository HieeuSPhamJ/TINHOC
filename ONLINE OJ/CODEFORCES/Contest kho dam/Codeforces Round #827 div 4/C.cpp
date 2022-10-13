#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int n = 8;
int a[10][10];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;

    while(test--){
        memset(a,0,sizeof(a));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                char inp;
                cin >> inp;
                if (inp == 'B'){
                    a[i][j] = 1;
                }
                if (inp == 'R'){
                    a[i][j] = 2;
                }
                
            }
        }

        int check = 0;

        for (int i = 1; i <= n; i++){
            int sum = 0;
            for (int j = 1; j <= n; j++){
                if (a[i][j] == 2)
                sum += a[i][j];
            }
            if (sum == 2 * 8){
                check = 2;
            }
        }
        for (int i = 1; i <= n; i++){
            int sum = 0;
            for (int j = 1; j <= n; j++){
                if (a[j][i] == 1)
                sum += a[j][i];
            }
            if (sum == 8){
                check = 1;
            }
        }

        if (check == 1){
            cout << "B";
        }
        else{
            cout << "R";
        }
        cout << endl;
    }
    return 0;
}