// LUOGU_RID: 96828563
#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') f=(ch=='-')?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=500010;
int ver[N],ne[N],head[N],tot,dfn[N],cnt,d[N],b[N],e[N],dfnn[N];//e是异或的累加，b是每个点的数值，d是深度 
vector<int> a[N],c[N];//a是dfs序，c是前缀和 
inline int max(int x,int y){return (x>y)?x:y;}
void add(int x,int y){ver[++tot]=y,ne[tot]=head[x],head[x]=tot;}
void dfs(int x,int f)
{
	dfn[x]=++cnt,d[x]=d[f]+1,a[d[x]].push_back(dfn[x]),e[d[x]]^=b[x],c[d[x]].push_back(e[d[x]]);
	for(int i=head[x];i;i=ne[i]) dfs(ver[i],x);
	dfnn[x]=cnt;
}
int main()
{
    
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
	int n=read(),m=read();
	for(int i=2;i<=n;i++) add(read(),i);
	string s;cin>>s;
	for(int i=0;i<n;i++) b[i+1]=1<<(s[i]-'a');
	dfs(1,0);
	while(m--)
	{
		int x=read(),y=read();
		int l=lower_bound(a[y].begin(),a[y].end(),dfn[x])-a[y].begin(),r=upper_bound(a[y].begin(),a[y].end(),dfnn[x])-a[y].begin()-1;
		if(r==-1)
		{
			puts("Yes");
			continue;
		}
		int ss;
		if(l==0) ss=c[y][r];
		else ss=c[y][r]^c[y][l-1];
		if(ss-(ss&-ss)) puts("No");
		else puts("Yes");
	}
	return 0;
}