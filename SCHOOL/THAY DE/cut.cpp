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
    freopen("cut.INP", "r", stdin);
    freopen("cut.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int k = -1;
    int l = 0;
    int r = 1e9;
    while(l <= r){
        int mid = (l + r) / 2;
        if (1 + mid * (mid + 1) / 2 >= n){
            k = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << k << endl;
    return 0;
}