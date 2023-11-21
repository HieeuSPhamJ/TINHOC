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
        int res = 0;
        for (int i = n - 2; i >= 0; i--){
            if(ls[i] > ls[i + 1]){
                if(ls[i] % ls[i + 1]){
                    res += ls[i] / ls[i + 1];
                    int x = (ls[i + 1] - ls[i] % ls[i + 1]) / (ls[i] / ls[i + 1] + 1);
                    int y = x + 1;
                    int z = x - 1;
 
                    int t1 = min(ls[i] % ls[i + 1] + ls[i] / ls[i + 1] * x , ls[i + 1] - x);
                    t1 = max(t1, min(ls[i] % ls[i + 1] + ls[i] / ls[i + 1] * y , ls[i + 1] - y));
                    t1 = max(t1, min(ls[i] % ls[i + 1] + ls[i] / ls[i + 1] * z , ls[i + 1] - z));
                    ls[i] = t1;
                }
                else{
                    res += ls[i] / ls[i + 1] - 1;
                    ls[i] = ls[i + 1];
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}