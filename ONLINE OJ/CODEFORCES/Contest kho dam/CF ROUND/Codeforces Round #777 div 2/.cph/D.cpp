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
        int n, d;
        cin >> n >> d;
        int check = 1;
        if (n % (d * d * d * d) == 0){
            check = 0;
        }
        n /= (d * d);
        int cnt = 0;
        for (int i = 2; i * i <= n; i++){
            if (n % i == 0){
                cnt++;
            }
        }
        // cout << n << " " << cnt << endl;
        if (cnt >= 2){
            check = 0;
        }
        if (check){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}