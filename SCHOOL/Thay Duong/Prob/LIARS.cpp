#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("LIARS.inp", "r")) {
        freopen("LIARS.inp", "r", stdin);
        freopen("LIARS.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <ii> ls;
    for (int i = 1, x; i <= n; i++){
        char c;
        cin >> c >> x;
        if (c == 'L'){
            ls.push_back({0,x});
        }
        else{
            ls.push_back({x,1e9});
        }
    }
    multiset <int> s;
    sort(all(ls));
    int res = 0;
    for (auto i: ls){
        while(s.size() and *s.begin() < i.fi){
            s.erase(s.begin());
        }
        s.insert(i.se);
        res = max(res, (int)s.size());   
    }
    cout << n - res << endl;
    return 0;
}