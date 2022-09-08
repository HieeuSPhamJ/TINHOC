#include <bits/stdc++.h>
using namespace std;
int p[100005][100],h[100005],n,q;
vector <int> a[100005];
void dfs(int x, int pre)
{
    for (int i=0;i<a[x].size();i++)
    {
        if (a[x][i]!=pre)
        {
            p[a[x][i]][0]=x;
            h[a[x][i]]=h[x]+1;
            dfs(a[x][i],x);
        }
    }
}
void tim()
{
    for (int i=1;(1<<i)<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            p[j][i]=p[p[j][i-1]][i-1];
        }
    }
}
int lca(int x, int y)
{
    int ans=0;
    if (h[x]<h[y])
    {
        swap(x,y);
    }
    int tam=log2(h[x]);
    for (int i=tam;i>=0;i--)
    {
        if (h[x]-(1<<i)>=h[y])
        {
            x=p[x][i];
            ans+=(1<<i);
        }
    }
    if (x==y)
    {
        return ans;
    }
    for (int i=tam;i>=0;i--)
    {
        if (p[x][i]!=p[y][i] && p[x][i]!=0)
        {
            ans+=(1<<(i+1));
            x=p[x][i];
            y=p[y][i];
        }
    }
    return ans;
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,0);
    tim();
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        int x,y,u,v,k;
        cin>>x>>y>>u>>v>>k;
        int tam1=lca(u,v);
        int tam2=lca(u,x)+lca(y,v)+1;
        int tam3=lca(u,y)+lca(x,v)+1;
        tam2=min(tam2,tam3);
        if ((tam1%2==k%2 && k>=tam1) || (tam2%2==k%2 && k>=tam2))// || (tam3%2==k%2 && k>=tam3))
        {
            cout<<"YES"<<"\n";
            continue;
        }
        cout<<"NO"<<"\n";
    }
}
