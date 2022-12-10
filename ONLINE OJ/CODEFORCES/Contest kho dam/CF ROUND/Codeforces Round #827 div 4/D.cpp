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
        map <int,int> a;
        for (int i = 1; i <= n; i++){
            int inp;
            cin >> inp;
            a[inp] = i;
        }
        int ans = -1;
        for (int i = 1; i <= 1000; i++){
            if (a[i] == 0){
                continue;
            }
            for (int j = i; j <= 1000; j++){
                if (a[j] == 0){
                    continue;
                }
                if (__gcd(i,j) == 1){
                    ans = max(ans, a[i] + a[j]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}