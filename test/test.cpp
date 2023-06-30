#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n;
vector<int> g[N];
int dp[N], pre[N], suf[N];
void dfs1(int x, int fa)
{
	dp[x] = 1;
	int p = 0, s = 0;
	for (int i = 0; i < g[x].size(); i++)
	{
		int y = g[x][i];
		if (y == fa)
			continue;
		dfs1(y, x);
		dp[x] = 1ll * dp[x] * (dp[y] + 1) % mod;
	}
	for (int i = 0; i < g[x].size(); i++)
	{
		int y = g[x][i];
		if (y == fa)
			continue;
		pre[y] = 1ll * pre[p] * (dp[p] + 1) % mod;
		p = y;
	}
	for (int i = g[x].size() - 1; i >= 0; i--)
	{
		int y = g[x][i];
		if (y == fa)
			continue;
		suf[y] = 1ll * suf[s] * (dp[s] + 1) % mod;
		s = y;
	}
}
void dfs2(int x, int fa, int tag)
{
	for (int i = 0; i < g[x].size(); i++)
	{
		int y = g[x][i];
		if (y == fa)
			continue;
		dp[y] = (1ll * tag * suf[y] % mod * pre[y] % mod + 1) % mod * dp[y] % mod;
		dfs2(y, x, (1ll * tag * suf[y] % mod * pre[y] % mod + 1) % mod);
	}
}
signed main()
{
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		g[x].push_back(i);
		g[i].push_back(x);
	}
	pre[0] = suf[0] = 1;
	dfs1(1, 0);
	dfs2(1, 0, 1);
	for (int i = 1; i <= n; i++)
		cout << dp[i] << " ";
	return 0;
}