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
        int n, m, k;
        cin >>  n >> m >> k;
        int t = n / k;
        int d = n % k;
        int ok = 1;
        int mm = -1;
        for (int i = 1; i <= m; i++){
            int x;
            cin >> x;
            mm = max(mm,x);
        }

        if (mm == 1){
            cout << "YES" << endl;
            continue;
        }

        if ((n - 1) / (mm - 1) < k){
            ok = 0;
        }

        if (ok){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }   
    return 0;
}