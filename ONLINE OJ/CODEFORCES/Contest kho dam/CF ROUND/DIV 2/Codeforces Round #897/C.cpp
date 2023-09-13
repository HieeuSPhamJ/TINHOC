#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
// #define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

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
        vector <int> ls;
        set <int> res;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            ls.push_back(x);
            res.insert(i);
        }
        res.insert(0);
        res.insert(n + 1);
        
        for (auto i: ls){
            if (res.find(i) != res.end()){
                res.erase(res.find(i));
            }
        }
        while(1){
            auto it = res.begin();
            cout << *it << endl;
            res.erase(it);
            int t;
            cin >> t;
            if (t != -1){
                res.insert(t);
                continue;
            }
            break;
        }

    }
    return 0;
}