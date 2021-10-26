#include <bits/stdc++.h>
using namespace std;

int m,n,k;
int a[2010][2010];
long long b[100010];

bool cmp(int a,int b){
return a>b;
}

int main()
{
    freopen("frog.inp","r",stdin);
    freopen("frog.out","w",stdout);
    memset(b,0,sizeof(b));
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++)
        for (int e=1;e<=n;e++) { cin>>a[i][e]; b[a[i][e]]++; }
    sort(b+1,b+100011,cmp);
    int s=0;
    //for (int i=1;i<=k;i++) cout<<b[i]<<endl;
    for (int i=1;i<=k;i++) s+=b[i];
    cout<<s;
    return 0;
}
