#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define p1 "Hoang"
#define p2 "Vuong"
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
        for (int i = 1; i <= n; i++){
            int a;
            cin >> a >> a;
        }
        if (n <= 2){
            cout << p1 << endl;
            continue;
        }
        int m = n / 2;
        if (m % 2){
            cout << p1;
        }
        else{
            cout << p2;
        }
        cout << endl;
    }
    return 0;
}