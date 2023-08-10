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
        int n, m;
        cin >> n >> m;
        if (n > m){
            cout << "NO" << endl;
            continue;
        }
        if (n % 2 == 1){
            cout << "YES" << endl;
            for (int i = 1; i < n; i++){
                cout << 1 << ' ';
            }
            cout << m - (n - 1) << endl;
            continue;
        }
        if (m % 2 == 0){
            cout << "YES" << endl;
            for (int i = 1; i <= n - 2; i++){
                cout << 1 << ' ';
            }
            cout << (m - (n - 2)) / 2 << " " << (m - (n - 2)) / 2 << endl;
            continue;            
        }
        cout << "NO" << endl;
    }
    return 0;
}


/*
4 5
1 1 1 2

*/