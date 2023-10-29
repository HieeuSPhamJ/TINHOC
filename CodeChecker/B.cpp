#include <bits/stdc++.h>
// #define int long long
#define ii pair<int, int>
#define iii pair<int,ii>
#define vii vector<ii>
#define fi first
#define se second
#define endl '\n'
using namespace std;
const double eps = 0.000001;
const int mod = 1000000007;
const int N = 101;
const int MATRIX_SIZE = 3;
int n,dp[2][N][10001],dp2[2][N][10001],s=0,l,r,k,T[N],ans=1e9;
void solve(){
	cin>>n>>l>>r>>k;
	for (int i=1;i<=n;++i){
		cin>>T[i];
		if (i>=l&&i<=r) s+=T[i];
	}
	for (int i=0;i<l;++i)
		for (int j=l-1;j<=r;++j)
			for (int time=0;time<=k;++time){
				dp[i&1][j][time]=s;
				if (j-i>time) continue;
				if (i>0&&j>=l&&time>0){
					dp[i&1][j][time]=min({dp[(i&1)^1][j-1][time-j+i]+(T[i]-T[j]),dp[i&1][j-1][time],dp[(i&1)^1][j][time],dp[i&1][j][time-1]});
				for (int i2=r;i2<=n;++i2)
					for (int j2=j;j2<=r;++j2)
						for (int time2=0;time2<=k-time;++time2){
							dp2[i2&1][j2][time2]=dp[i&1][j][time];
							if (i2-j2>time2) continue;
							if (i2>r&&j2>j&&time2>0)
								dp2[i2&1][j2][time2]=min({dp2[(i2&1)^1][j2-1][time2-i2+j2]+T[i2]-T[j2],dp2[i2&1][j2-1][time2],dp2[(i2&1)^1][j2][time2],dp2[i2&1][j2][time2-1]});
						}
				ans=min(ans,dp2[n&1][r][k-time]);
				}
			}
	for (int i2=r;i2<=n;++i2)
		for (int j2=l-1;j2<=r;++j2)
			for (int time2=0;time2<=k;++time2){
				dp2[i2&1][j2][time2]=s;
				if (i2-j2>time2) continue;
				if (i2>r&&j2>=l&&time2>0){
					dp2[i2&1][j2][time2]=min({dp2[(i2&1)^1][j2-1][time2-i2+j2]+T[i2]-T[j2],dp2[i2&1][j2-1][time2],dp2[(i2&1)^1][j2][time2],dp2[i2&1][j2][time2-1]});
					// cout<<i2<<' '<<j2<<' '<<time2<<' '<<dp2[i2&1][j2][time2]<<endl;
				}

			}
	ans=min(ans,dp2[n&1][r][k]);
	cout<<ans << endl;
}
signed main() {
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// cin>>t;
	// while (t--)
    solve();
}
//dp[i][j][time]=min(dp[i-1][j-1][time-|i-j|],dp[i][j-1][time],dp[i-1][j-1][time])