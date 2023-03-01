#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int dp[100][100];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        string a, b;
        cin >> a >> b;
        int n = a.length();
        int m = b.length();
        a = "!" + a;
        b = "!" + b;

        int ok = 0;

        if (a[1] == b[1]){
            ok = 1;
        }
        if (a[n] == b[m]){
            ok = 2;
        }
        int id = -1;
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                if (a[i] == b[j] and a[i + 1] == b[j + 1]){
                    ok = 3;
                    id = i;
                    goto bru;
                }
            }
        }

        bru:;

        if (ok){
            cout << "YES" << endl;
            if (ok == 1){
                cout << a[1] << "*" << endl;
            }
            else if (ok == 2){
                
                cout << "*" << a[n] << endl;
            }
            else{
                cout << "*" << a[id] << a[id + 1] << "*" << endl;
            }
        }
        else{
            cout << "NO" << endl;
        }
        
    }
    return 0;
}