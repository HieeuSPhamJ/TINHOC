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
        int a, b;
        cin >> a >> b;
        int g = __gcd(a,b);
        a /= g;
        b /= g;
        ls.push_back({a,b});
        cnt[{a,b}]++;
    }
    int res = 0;
    for (auto i: ls){
        int a = i.fi;
        int b = i.se;   
        swap(a,b);
        a = -a;
        res += cnt[{a,b}];
    }
    cout << res << endl;
    return 0;
}