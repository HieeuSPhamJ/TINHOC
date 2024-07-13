#include"bits/stdc++.h"
#define int long long
using namespace std;

int a[5010];

signed main(){
    int test;
    cin >> test;
    while(test--){
        int n, x;
        cin >> n >> x;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }

        sort(a + 1, a + 1 + n);
        
        int ans = 0;

        for (int i = 1; i <= n; i++){     
            if (x * i >= a[i]){
                ans++;
            }
            else{
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
