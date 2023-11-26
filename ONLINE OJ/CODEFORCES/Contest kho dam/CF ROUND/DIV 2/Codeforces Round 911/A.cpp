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
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int la = -1;
        vector <int> ls;
        for (int i = 1; i <= n; i++){
            char c;
            cin >> c;
            if (la == -1 and c == '.'){
                la = i;
            }
            if (la != -1 and c == '#'){
                ls.push_back(i - la);
            }
            if (c == '#'){
                la = -1;
            }
        }
        if (la != -1){
            ls.push_back(n - la + 1);
        }
        sort(all(ls));
        int res = 0;
        while(ls.size()){
            if (ls.back() > 2){
                res = 2;
                break;
            }
            else{
                res += ls.back();
                ls.pop_back();
            }
        }
        cout << res << endl;
    }
    return 0;
}