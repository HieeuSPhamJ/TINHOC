#include <bits/stdc++.h>
using namespace std;
int main()
{
	int test;
    cin >> test;
	while(test--){
		int pre[200007];
		string s;
		cin >>s;
		int n = s.length();
		s = "?" + s;
		for(int i = 1; i<=n; i++)pre[i] = pre[i-1]+(s[i] == '0');
		int cnt1 = count(s.begin(), s.end(), '1');
		int ans = 1e9;	
		for(int i = cnt1; i<=n; i++)ans = min(ans, pre[i] - pre[i-cnt1]);
		cout << ans << endl;   
	}
}