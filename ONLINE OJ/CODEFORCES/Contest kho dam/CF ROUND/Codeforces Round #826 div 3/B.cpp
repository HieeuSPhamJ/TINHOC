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
        int n;
        cin >> n;
        if (n == 3){
            cout << -1 << endl;
        }
        else if (n % 2 == 0){
            for (int i = n; i >= 1; i--){
                cout << i << ' ';
            }
            cout << endl;
        }
        else{
            int t = (n + 1) / 2;
            cout << t << ' ';
            for (int i = t + 1; i <= n; i++){
                cout << i << ' ';
            }
            for (int i = 1; i < t; i++){
                cout << i << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}