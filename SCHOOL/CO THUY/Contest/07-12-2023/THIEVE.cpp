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

const int maxN = 1e6 + 10;

ii a[maxN];

bool cmp(ii x, ii y){
	if(x.se != y.se){
        return x.se > y.se;
    }
	return x.fi < y.fi;
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("thieve.inp", "r")) {
        freopen("thieve.inp", "r", stdin);
        freopen("thieve.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
	
	for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
		
	sort(a + 1, a + 1 + n, cmp);
    multiset <int> s;
	for(int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        s.insert(x);
	}
	
	int res = 0;

	for(int i = 1; i <= n; i++) {
		if(s.empty()){
            break;
        }
		if(s.lower_bound(a[i].fi) != s.end()) {
			res += a[i].se;
			s.erase(s.lower_bound(a[i].fi));
		}
	}
    
    cout << res << endl;

    return 0;
}
