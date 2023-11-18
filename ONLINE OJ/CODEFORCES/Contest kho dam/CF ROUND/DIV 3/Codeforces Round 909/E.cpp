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
        vector <int> ls;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            ls.push_back(x);
        }
        vector <int> tmp = ls;
        sort(all(tmp));
        tmp.erase(unique(all(tmp)), tmp.end());
        for (auto &i: ls){
            i = lower_bound(all(tmp), i) - tmp.begin();
            // cout << i << " ";
        }
        // cout << endl;
        ls.push_back(1e18);
        int res = -1;
        for (int i = n - 1; i >= 0; i--){
            if (ls[i] <= ls[i + 1]){
                res = i;
                continue;
            }
            // cout << i << endl;
            if (ls[i + 1] != 0){
                res = -1;
            }
            break;
        }

        for (int i = 0; i < res; i++){
            if (ls[i] == 0){
                res = -1;
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}

/*
4 5 3 7 8 6 2



*/