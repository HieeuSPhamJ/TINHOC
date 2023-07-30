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
    freopen("A.out", "r", stdin);
    freopen("B.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x;
    cin >> x;
    if (x > 31){
        cout << -1;
        return 0;
    }
    cout << x;
    return 0;
}