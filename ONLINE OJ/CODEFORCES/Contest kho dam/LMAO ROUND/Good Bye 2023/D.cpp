#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        if (n == 1){
            cout << 1 << endl;
            continue;
        }
        if (n == 3){
            cout << 169 << endl << 196 << endl << 961 << endl;
            continue;
        }
        int a = 0, b = n - 3;
        for (int x = 1; b >= 0; x++){
            // cout << a << " " << b << endl;
            cout << 9;
            for (int i = 1; i <= a; i++){
                cout << 0;
            }
            cout << 6;
            for (int i = 1; i <= a; i++){
                cout << 0;
            }
            cout << 1;
            for (int i = 1; i <= b; i++){
                cout << 0;
            }
            cout << endl;
            a++;
            b -= 2;
        }
        a = 0, b = n - 3;
        for (int x = 1; b >= 0; x++){
            // cout << a << " " << b << endl;
            cout << 1;
            for (int i = 1; i <= a; i++){
                cout << 0;
            }
            cout << 6;
            for (int i = 1; i <= a; i++){
                cout << 0;
            }
            cout << 9;
            for (int i = 1; i <= b; i++){
                cout << 0;
            }
            cout << endl;
            a++;
            b -= 2;
        }
        cout << 196;
        for (int i = 1; i <= n - 3; i++){
            cout << 0;
        }
        cout << endl;

    }
    return 0;
}