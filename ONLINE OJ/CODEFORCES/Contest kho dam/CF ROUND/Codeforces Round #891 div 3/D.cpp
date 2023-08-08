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

const int maxN = 2e5 + 10;

ii a[maxN];


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
        for (int i = 1; i <= n; i++){
            cin >> a[i].fi;
        }
        vector <ii> te;
        for (int i = 1; i <= n; i++){
            cin >> a[i].se;
            te.push_back({a[i].fi - a[i].se, i});
        }
        sort(rall(te));

        vector <int> res;

        for (auto i: te){
            if (te[0].fi == i.fi){
                res.push_back(i.se);
            }
        }

        sort(all(res));
        // cout << "TEST" << endl;
        cout << res.size() << endl;
        for (auto i: res){
            cout << i << " ";
        }
        cout << endl;
        
    }
    return 0;
}