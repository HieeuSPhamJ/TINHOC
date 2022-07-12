#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int ans = 1e9;
        int temp = 1;
        
        while (temp <= n){
            ans = min(ans, n - temp);
            temp *= 10;
        }

        cout << ans << endl;
    }
    return 0;
}