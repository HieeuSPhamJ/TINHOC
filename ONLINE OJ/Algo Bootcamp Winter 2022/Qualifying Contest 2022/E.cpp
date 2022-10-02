#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int cal(int n){
    return (n * (n + 1)) / 2;
}

int sum(int n, int len){
    return cal(n) - cal(n - len);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    ans += sum(n - 1, m - (m - n));
    ans += sum(m - 2, n - 1);
    cout << ans;
    return 0;
}