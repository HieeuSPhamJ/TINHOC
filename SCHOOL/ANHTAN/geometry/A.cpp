#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

map <ii,int> cnt;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <ii> ls;
    for (int i = 1; i <= n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        int g = __gcd(a,b);
        a /= g;
        b /= g;
        // cout << a << " " << b << endl;
        cnt[{a,b}]++;
        ls.push_back({a,b});
    }
    int ans = n * (n - 1);
    for (auto i: ls){
        ans -= (cnt[i] - 1);
    }
    cout << ans / 2 << endl;
    return 0;
}