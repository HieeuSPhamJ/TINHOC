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
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (x == 1){
            continue;
        }
        x--;
        x = log2(x);
        res += (1 << x);
    }
    cout << res << endl;
    return 0;
}