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

int a[maxN];
int b[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        // cout << "===TEST===" << endl;
        int n;
        cin >> n;
        
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
            cin >> b[i];
        }
        vector <int> minus;
        vector <int> add;
        
        int res = -1e18;
        for (int i = 1; i <= n; i++){
            if (b[i] == 1){
                add.push_back(a[i]);
            }
            else{
                minus.push_back(a[i]);
            }
            res = max(res,a[i] * b[i]);
        }
        sort(all(add));
        sort(rall(minus));
        vector <ii> ls;
        for (auto i: add){
            ls.push_back({i,1});
        } 
        for (auto i: minus){
            ls.push_back({i,-1});
        } 
        
        for (int i = 0, sum = 0, k = 0; i < ls.size(); i++){
            sum += ls[i].fi;
            k += ls[i].se;
            // cout << ls[i].fi << ' ' << ls[i].se << endl;
            res = max(res, sum * k);
        }
        cout << res << endl;
    }
    return 0;
}