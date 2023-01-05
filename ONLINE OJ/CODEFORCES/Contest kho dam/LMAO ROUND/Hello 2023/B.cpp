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
            cout << "NO" << endl;
        }
        else if (n % 2){
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++){
                if (i % 2 == 1){
                    cout << 3 - n << ' ';
                }
                else{
                    cout << n - 1 << ' ';
                }
            }
            cout << endl;
        }
        else{
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++){
                if (i % 2){
                    cout << 1;
                }
                else{
                    cout << -1;
                }
                cout << " ";    
            }
            cout << endl;
        }
    }
    return 0;
}