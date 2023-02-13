#include <cstdio>
#include <algorithm>
#include <vector>
const int N=1e5+10;
struct node
{
    int i,l,r;
    bool friend operator <(node n1,node n2){return n1.r<n2.r;}
}q[N<<2];
int ans[N<<2],Ans[N<<2],n,m,a[N],mi;
std::vector <int> seg[N<<2];
int min(int x,int y){return x<y?x:y;}
#define ls id<<1
#define rs id<<1|1
const int inf=0x3f3f3f3f;
void build(int id,int l,int r)
{
    for(int i=l;i<=r;i++) seg[id].push_back(a[i]);
    std::sort(seg[id].begin(),seg[id].end());
    ans[id]=inf;
    if(l==r) return;
    int mid=l+r>>1;
    build(ls,l,mid),build(rs,mid+1,r);
}
void change(int id,int l,int r,int p,int x)
{
    if(r<=p)
    {
        std::vector <int>::iterator it=std::upper_bound(seg[id].begin(),seg[id].end(),x);
        if(it!=seg[id].end()) ans[id]=min(ans[id],*it-x);
        if(it!=seg[id].begin()) ans[id]=min(ans[id],x-*(it-1));
        if(mi<=ans[id]) return;//右边已经有比Ta优秀的了
        if(l==r){mi=min(mi,ans[id]);return;}
    }
    int mid=l+r>>1;
    if(p>mid) change(rs,mid+1,r,p,x);//注意先走右边
    change(ls,l,mid,p,x);
    ans[id]=min(ans[id],min(ans[ls],ans[rs]));
    mi=min(mi,ans[id]);//最后更新Ta
}
int query(int id,int L,int R,int l,int r)
{
    if(L==l&&R==r) return ans[id];
    int Mid=L+R>>1;
    if(r<=Mid) return query(ls,L,Mid,l,r);
    else if(l>Mid) return query(rs,Mid+1,R,l,r);
    else return min(query(ls,L,Mid,l,Mid),query(rs,Mid+1,R,Mid+1,r));
}
int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].i=i;
    }
    std::sort(q+1,q+1+m);
    for(int p=1,i=2;i<=n;i++)
    {
        mi=inf;
        change(1,1,n,i-1,a[i]);
        for(;p<=m&&q[p].r<=i;++p)
            Ans[q[p].i]=query(1,1,n,q[p].l,i);
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",Ans[i]);
    return 0;
}
