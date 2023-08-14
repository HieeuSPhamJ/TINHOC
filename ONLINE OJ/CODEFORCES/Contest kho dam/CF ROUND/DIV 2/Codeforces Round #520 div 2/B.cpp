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
    int res = 1;
    int cnt = 0;
    int tem = 0;
    if (n <= 1){
        cout << n << " " << 0 << endl;
        return 0;
    }
    for (int i = 2; i <= n; i++){
        if (n % i == 0){
            int t = 0;
            while(n % i == 0){
                n /= i;
                t++;
            }
            if (cnt != t and res != 1){
                tem = 1;
            }
            cnt = max(cnt, t);
            // cout << i << " " << t << endl;
            if (t != (1 << ((int)log2(t)))){
                tem = 1;
            }
            res *= i;
        }
    }
    int mu = ceil(log2(cnt));
    // cout << "tem: " << mu << " " << tem << endl;
    cout << res << " " << mu + tem << endl;

    return 0;
}