#include"bits/stdc++.h"
#define int long long
using namespace std;

signed main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        map <int,int> a;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        
        vector <pair <int,int>> res;

        for (int i = 1; i < n; i++){
            for (int j = i + 1; j <= n; j++){
                if (a[i] == i){
                    goto bru;
                }
                if (a[i] != i and a[j] * 1.0 == i * 1.0){
                    res.push_back({j, n + 1});
                    break;
                }
            }

            for (int j = res.back().first; i < j; j--){
                a[j] = a[j - 1];
                res.push_back({j - 1, j});
            }

            res.push_back({n + 1, i});
            bru:;
        }

        cout << res.size() << endl;

        for (int i = 0; i < n; i++){
            cout << res[i].first << " " << res[i].second << endl;
        }
    }
    return 0;
}
