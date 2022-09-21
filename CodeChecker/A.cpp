#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

char a[10000];
char b[10000];
int check[10000];


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
        memset(check, 0, sizeof(check));
        int n, x, y;
        cin >> n >> x >> y;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
            cin >> b[i];
        }
        int countDiff = 0;
        for (int i = 1, last = 1; i <= n; i++){
            if (a[i] != b[i]){
                countDiff++;
                check[last] = i;
                last++;
            }
        }
        if (countDiff % 2 == 0){
            if (countDiff != 2){
                cout << countDiff * y  / 2 << endl;
            }
            else {
                if (check[2] == check[1] + 1){
                    if (x <= 2 * y){
                        cout << x << endl;
                    }
                    else{
                        cout << 2 * y << endl;
                    }
                    continue;
                }
            }
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}