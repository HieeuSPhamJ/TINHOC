#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
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
        int n, m, x, y, d;
        cin >> n >> m >> x >> y >> d;
        int check = 0;
        // cout << abs(x - 1) - d << " ";
        if ((abs(x - 1) - d >= 1 and abs(y - m) - d >= 1) or (abs(y - 1) - d >= 1 and abs(x - n) - d >= 1)){
            check = 1;
        }
        if (check == 0){
            cout << -1;
            cout << endl;
        }
        else{
            cout << (n - 1) + (m - 1) << endl;
        }
    }
    return 0;
}