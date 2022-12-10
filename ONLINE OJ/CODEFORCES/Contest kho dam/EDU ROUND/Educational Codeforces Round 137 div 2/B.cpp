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
        int a[100] = {0};
        a[1] = 1;
        a[n] = 2;
        for (int i = 2, cnt = 3; i < n; i++){
            a[i] = cnt;
            cnt++;
        }
        for (int i = 1; i <= n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}