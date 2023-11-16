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

const int maxN = 2010;

int a[maxN];

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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        int mask = 0;
        while(x){
            int c = x % 10;
            x /= 10;
            mask = mask | (1 << c);
        }
        a[mask]++;
    }
    int res = 0;

    for (int i = 0; i < (1 << 10); i++){
        for (int j = 0; j < (1 << 10); j++){
            if (i & j){
                // if (a[i] and a[j]){
                //     // cout << bitset<10>(i) << " " << bitset<10>(j) << " " << a[i] * (a[j] - 1) << endl;
                // }
                if (i == j){    
                    res += a[i] * (a[j] - 1);
                }   
                else{  
                    res += a[i] * a[j];
                }
            }
        }
    }

    cout << res / 2 << endl;
    return 0;
}