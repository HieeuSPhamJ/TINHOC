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
        int n;
        cin >> n;
        int a = pow(2,n);
        int nh = n / 2;
        for (int i = 1; i <= nh - 1; i++){
            // cout << i << " ";
            a += pow(2,i);
        }
        // cout <<"| ";
        for (int i = nh; i <= n - 1; i++){
            // cout << i << " ";
            a -= pow(2,i);
        }

        cout << endl;

        cout << abs(a) << endl;
    }
    return 0;
}