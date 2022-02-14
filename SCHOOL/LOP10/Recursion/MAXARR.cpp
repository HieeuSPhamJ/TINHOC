#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("MAXARR.INP", "r", stdin);
    freopen("MAXARR.OUT", "w", stdout);
    int n;
    cin >> n;
    int inp;
    cin >> inp;
    int ans = inp;
    for (int i = 1; i < n; i++){
        cin >> inp;
        ans = max(inp, ans);

    }
    cout << ans;
    
    return 0;
}