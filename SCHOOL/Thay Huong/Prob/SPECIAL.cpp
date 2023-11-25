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
    if (fopen("SPECIAL.inp", "r")) {
        freopen("SPECIAL.inp", "r", stdin);
        freopen("SPECIAL.out", "w", stdout);
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
        for (int i = 1; i * i <= n; i++){
            if (n % i == 0){
                ls.push_back(i);
                if (n / i != i){
                    ls.push_back(n / i);
                }
            }
        }
        sort(all(ls));
        int ok = 0;
        for (int i = 1; i < (int)ls.size(); i++){
            if (ls[i] == ls[i - 1] + 1){
                cout << ls[i - 1] << " ";
                ok = 1;
            }
        }
        if (ok == 0){
            cout << -1;
        }
        cout << endl;
    }
    return 0;
}