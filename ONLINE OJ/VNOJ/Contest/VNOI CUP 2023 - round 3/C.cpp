#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int a[20];

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
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ok = 0;
        for (int mask = 0; mask < (1 << n); mask++){
            int td = __builtin_popcount(mask);
            // cout << "With: " << bitset<3>(mask) << endl;
            for (int i = 0, cntd = 0; i < n; i++){
                td -= ((mask & (1 << i)) != 0);
                int t = (cntd >= td);
                if (((mask & (1 << i)) == 0)){
                    t = !t;
                }
                // cout << (cntd >= td) << " " << t << " " << a[i] << endl;
                if (t != a[i]){
                    // cout << "lmao" << endl;
                    goto bru;
                }
                cntd += ((mask & (1 << i)) != 0); 
            }
            ok = 1;
            // cout << "*" << bitset<3>(mask) << endl;
            for (int i = 0; i < n; i++){
                cout << ((mask & (1 << i)) != 0) << " "; 
            } 
            cout << endl;
            break;
            bru:;
        }
        if (!ok){
            cout << -1 << endl;
        }
    }
    return 0;
}