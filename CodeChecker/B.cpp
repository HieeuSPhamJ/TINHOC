#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 1e5+5 , INF = 1e18 , MOD = 1e9+7;

string fin = " hard",s;
vector<ll> a(N);
ll dp[N][5];
ll n;

ll go(ll i , ll j){

	if(j == 4) return INF;
	if(i == n+1) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	ll ans = INF;

	ans = min(ans,go(i+1,j+(s[i] == fin[j+1])));
	ans = min(ans,go(i+1,j)+a[i]);

	return dp[i][j] = ans;
}

void solve(){

	cin >> n >> s;
	s = ' '+s;
	for(ll i = 1; i <= n; i++) cin >> a[i];

	memset(dp,-1,sizeof dp);
	cout << go(1,0);
}

int main(){

	fast;
	freopen("input.inp", "r", stdin);
	freopen("B.out", "w", stdout);

	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();

	return 0;
}