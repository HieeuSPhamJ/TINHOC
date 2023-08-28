#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int a[10000];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int x, y, n;
        cin >> x >> y >> n;
        a[1] = x;
        a[n] = y;
        for (int i = n - 1; i >= 1; i--){
            a[i] = a[i + 1] - (n - i);
        } 
        if (a[1] < x){
            cout << -1 << endl;
        }
        else{
            a[1] = x;
            for (int i = 1; i <= n; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}