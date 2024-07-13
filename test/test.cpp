#include"bits/stdc++.h"
#define int long long
//#define double long double
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
    int res = 0;
    for (int a = 1; a <= 100; a++){  
    for (int b = 1; b <= 100; b++){
    for (int c = 1; c <= 100; c++){  
    for (int d = 1; d <= 100; d++){
        // if (a * b == c * d){
        //     res++;
        // }
        if (sqrt(a * b)== sqrt(c * d)){
            res++;
        }
    }
    }
    }
    }
    cout << res << endl;
    return 0;
}