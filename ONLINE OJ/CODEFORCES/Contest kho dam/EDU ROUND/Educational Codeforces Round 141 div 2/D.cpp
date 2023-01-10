#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 310;
const int hx = 90000;
const int mod = 998244353;
int a[maxN];
int dp[maxN][180005];

signed main()
{
    // freopen("input.INP", "r", stdin);
    // freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[2][a[2]+hx]=1;
	for(int i=2;i<n;i++)
	{
		for(int j=0;j<=hx+hx;j++)
		{
			if(dp[i][j])
			{
				if(j!=hx)
				{
					dp[i+1][a[i+1]+j]+=dp[i][j];
					dp[i+1][a[i+1]-j+hx*2]+=dp[i][j];
				}
				else dp[i+1][a[i+1]+j]+=dp[i][j];
			}
		}
		for(int j=0;j<=hx+hx;j++) dp[i+1][j]%=mod;
	}
	int ans=0;
	for(int i=0;i<=hx+hx;i++) ans+=dp[n][i];
	cout<<ans%mod;
    return 0;
}
