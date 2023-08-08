#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<int, int>
#define endl '\n'
#define fi first
#define se second
#define pub push_back
#define pob pop_back
#define vi vector<int>
#define vii vector< vector<int> >
#define st stack<int>
#define prqueue priority_queue
#define emb emplace_back
int t, n, x, y;
map<int, int> mp;
int func(int s, int p){
	int dd=s*s-4*p;
	if(dd<0) return 0;
	int d=sqrt(dd);
	while(d*d<dd) d++;
	while(d*d>dd) d--;
	if(d*d!=dd) return 0;
	if(d==0){
		dd=mp[s/2];
		return dd*(dd-1)/2;
	}
	return mp[(d+s)/2]*mp[(s-d)/2];
}
signed main() {
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
	ios_base:: sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin>>t;
	while(t--){
		mp=map<int, int>();
		cin>>n;
		while(n--){
			cin>>x;
			mp[x]++;
		}
		cin>>n;
		while(n--){
			cin>>x>>y;
			cout<<func(x, y)<<" ";
		}
		cout<<endl;
	}
}