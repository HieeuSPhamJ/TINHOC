#include<bits/stdc++.h>
using namespace std;

const int maxN = 10000;
long long a[maxN];
long long sum[maxN];

int main(){
    freopen("SC6.INP", "r", stdin);
    freopen("SC6.OUT", "w", stdout);
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        sum[0] = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        long long ans = 0;
        for (int i = 1; i < n; i++){
            long long s = abs(sum[i] - (sum[n] - sum[i])); 
            // cout << sum[i] << ' ' << sum[n] - sum[i] << endl;
            // cout << s << endl;
            ans = max(s, ans);
        }
        cout << ans;
        cout << endl;
    }


    return 0;
}