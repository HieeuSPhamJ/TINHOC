#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
using namespace std;

const int MAXN = 2*1e5+10;

int a[MAXN];
int b[MAXN];

main(){
    fast;
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[i]=0;
        }
        for (int i=m+1; i<=n;i++)
            b[i]=b[i-1]+a[i];
        priority_queue <int> q;
        int ans=0;
        for (int i=m+1,tam=0;i<=n;i++)
        {
            if (a[i]<0)
                q.push(-a[i]);
            while(!q.empty() && b[i]+tam<0)
            {
                tam+=2*q.top();
                q.pop();
                ans++;
            }
        }
        for (int i=1;i<=m;i++)
            b[i]=b[i-1]+a[i];

        while(!q.empty())
            q.pop();

        for (int i=m,tam=0;i>=1;i--)
        {
            while(!q.empty() && b[i]<b[m]+tam)
            {
                tam-=2*q.top();
                q.pop();
                ans++;
            }
            if (a[i]>0)
                q.push(a[i]);
        }


        cout<<ans<<endl;
    }
}