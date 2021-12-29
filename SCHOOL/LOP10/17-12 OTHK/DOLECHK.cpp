#include<bits/stdc++.h>
using namespace std;

int n, k;
long long a[1000007];

bool cmp( int a, int b){
    return (a > b);
}

int main(){
    freopen ("DOLECHK.INP", "r", stdin);
    freopen ("DOLECHK.OUT", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, cmp);
    long long ans = 0;
    for (int i = 1;i <= k; i++){
        ans += a[i];
    }
    for (int i = n;i >= n - k  + 1; i--){
        ans -= a[i];
    }
    cout << ans;
    return 0;
}