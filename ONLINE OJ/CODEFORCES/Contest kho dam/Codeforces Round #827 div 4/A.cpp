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
        vector <int> a(3);
        for (int i = 0; i < 3; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (a[2] == a[0] + a[1]){
            cout << "YES";
        }
        else cout << "NO";
        cout << endl;
    }

    return 0;
}