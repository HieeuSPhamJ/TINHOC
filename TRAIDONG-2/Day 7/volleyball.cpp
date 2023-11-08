#include<bits/stdc++.h>
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
    if (fopen("volleyball.inp", "r")) {
        freopen("volleyball.inp", "r", stdin);
        freopen("volleyball.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++){
        int k, x, y;
        cin >> k >> x >> y;
        if (x < y){
            swap(x,y);
        }
        int res = k - x;
        if (res < 0){
            res = 0;
        }
        else{
            x += res;
        }
        while (x - y < 2){
            x += 1;
            res++;
        }
        cout << res;
        if (t != test){
            cout << " ";
        }
    }
    return 0;
}