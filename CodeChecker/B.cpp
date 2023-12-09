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
	freopen("input.inp", "r", stdin);
	freopen("B.out", "w", stdout);
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
    int res = 0;
    for (int i = pow(10, (int)log10(n)); i <= n; i++){
        int a = i;
        int b = n - i;
        if ((int)log10(b) != (int)log10(n)){
            break;
        }
        for (int la = -1; a; a/=10){
            if (la == a % 10){
                goto bru;
            }
            la = a % 10;
        }
        for (int la = -1; b; b/=10){
            if (la == b % 10){
                goto bru;
            }
            la = b % 10;
        }
        // cout << i << " " << n - i << endl;
        res++;
        bru:;
    }
    cout << res << endl;
	return 0;
}