#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
// #define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int N = 102;
const int INF = 1e18;

int n;
string s;
int a[N];

int ans[N][N];
int dp[2][N][N][N];

int calcDp(int c, int l, int r, int cnt);

int calcAns(int l, int r){
	if(l >= r) return 0;
	int &res = ans[l][r];
	if(res != -1) return res;

	res = 0;
	for(int cnt = 1; cnt <= r - l; ++cnt){
		res = max(res, calcDp(0, l, r, cnt) + a[cnt - 1]);
		res = max(res, calcDp(1, l, r, cnt) + a[cnt - 1]);
	}

	return res;
}

int calcDp(int c, int l, int r, int cnt){
	if(cnt == 0) return calcAns(l, r);
	int &res = dp[c][l][r][cnt];
	if(res != -1) return res;
	
	res = -INF;

	for(int i = l; i < r; ++i){
		if(c == s[i] - '0')
			res = max(res, calcAns(l, i) + calcDp(c, i + 1, r, cnt - 1));
	}

	return res;
}

signed main(){
	cin >> n >> s;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	
	memset(dp, -1, sizeof dp);
	memset(ans, -1, sizeof ans);

	cout << calcAns(0, n) << endl;	

	return 0;
}

/*
1 2 3 4 5 6 7
1 1 0 1 0 0 1

3 6 9 100 103 106 109 

*/