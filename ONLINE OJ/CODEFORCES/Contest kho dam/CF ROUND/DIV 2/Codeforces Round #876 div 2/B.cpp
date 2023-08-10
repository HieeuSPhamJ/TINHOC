#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

bool cmp(ii a, ii b){
    if (a.fi == b.fi){
        return a.se > b.se;
    }
    return a.fi < b.fi;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector <ii> ls;
        for (int i = 1; i <= n; i++){
            int a, b;
            cin >> a >> b;
            ls.push_back({a,b});
        }

        sort(all(ls), cmp);
        // for (auto i: ls){
        //     cout << i.fi << ' '<< i.se << endl;
        // }
        
        int res = 0;
        multiset <int> s;
        
        for (auto i: ls){
            while(*s.begin() == s.size() - 1){
                s.erase(s.begin());
            }
            if (i.fi > s.size()){
                s.insert(i.fi);
                res += i.se;
            }
        }
        
        cout << res << endl;
    }
    return 0;
}