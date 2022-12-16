#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        ii a[5];
        for (int i = 1; i <= 3; i++){
            cin >> a[i].fi >> a[i].se;
        }
        int check = 0;
        for (int i = 1; i <= 3; i++){
            for (int j = 1; j <= 3; j++){
                if (i == j){
                    continue;
                }
                for (int k = 1; k <= 4; k++){
                    if (j == k or k == i or i == j){
                        continue;
                    }
                    if (a[i].fi == a[j].fi and (a[i].se == a[k].se or a[j].se == a[k].se)){
                        check = 1;
                    }
                }
            }
        }
        if (check == 1){
            cout << "NO";
        }
        else{
            cout << "YES";
        }
        cout << endl;
    }
    return 0;
}