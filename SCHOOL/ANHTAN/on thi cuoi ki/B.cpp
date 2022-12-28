#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int n;
bool check[10];
 
void adu(int res, int x) {
	if (res == n) {
		cout << x << endl;
        return;
	}
    for (int i = 0 + (res == 0); i <= n; i++) {
        if (!check[i]){
            check[i] = 1;
            adu(res + 1, x * 10 + i);
            check[i] = 0;
        }
    }
	
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    adu(0,0);
    return 0;
}