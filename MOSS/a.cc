#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n,a[N],p;
double f[N];
main(){
    freopen("DOLLS.INP","r",stdin);
    freopen("DOLLS.OUT","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >>n;
    for (int i=1;i<=n;i++){
        cin >>a[i];
        f[i] = f[i-1] + a[i];
    }
    cin >>p;
    int ans = 0;
    for (int i=1;i<=n;i++) if (a[i] >= p) ans++;
    for (int i=1; i <= n; i++) {
        if (i > 1){
            int j = i - 1;
            while (j >= 1 && f[i] - f[j-1] >= p*(i-j+1)){
                j--;
                ans++;
            }
        }
    }
    cout <<ans;
}