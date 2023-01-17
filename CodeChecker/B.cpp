#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int a[N],dp[N],n,k;
ll s;
int main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;s+=a[i++]){
		scanf("%d",&a[i]);
		if(a[i]>k) a[i]=k;
	}sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=n;~i;s-=a[i--]){
		bool ok=1;
		for(int j=k-1;j>=max(k-s,0LL);j--)
			if(dp[j]){
				ok=0;break;
			}
		if(ok){
			printf("%d\n",i);break;
		}
		for(int j=k;j>=a[i];j--) dp[j]|=dp[j-a[i]];
	}
	return 0;
}