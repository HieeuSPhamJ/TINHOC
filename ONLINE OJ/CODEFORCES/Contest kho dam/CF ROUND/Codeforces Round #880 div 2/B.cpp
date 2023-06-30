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
        int n, k, g;
        cin >> n >> k >> g;
        int left = 0;
        int right = k;
        int ans = -1;
        while(left <= right){
            int mid = (left + right) / 2;
            int res = mid * g;
            if (res / n + (res % n != 0) > g / 2 - (g % 2 == 0)){
                right = mid - 1;
            }
            else{
                left = mid + 1;
                ans = res;
            }
        }
        cout << ans << endl;
    }
    return 0;
}