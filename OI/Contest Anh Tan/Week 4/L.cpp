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


int v = 0;
string s;
int co[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int old;

int backtrack(int n){
	if ((int)log10(n) != (int)log10(v)){
        return -1;
    }
    int cur = 0;
    int nn = n;
    while(nn){
        cur += co[nn % 10];
        nn /= 10;
    }
    if (cur != old){
        return backtrack(n + 1);
    }
	return n;
}

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
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++){
        old += (co[s[i] - '0']);
        v = v * 10 + (s[i] - '0');
    }
    int res = backtrack(v + 1);
    if (res == -1){
		cout << "NO SOLUTION";
	}
    else{
		cout << res;
	}
    return 0;
}