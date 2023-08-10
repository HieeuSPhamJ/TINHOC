#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
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
        int a[n + 10];
        int sum = 0;
        for (int i = 1; i <= n; i++){
            a[i] = i;
            sum += i;
        }
        a[1] = n - sum % n;
        if (a[1] == 0){
            a[1] = n;
        }
        for (int i = 1; i <= n; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}