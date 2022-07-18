#include <bits/stdc++.h>

using namespace std;
const int N=1e5+3;
const long long oo=1e18;

long long a[N],dp[N];
int n;

void OddSolve()
{
    long long ans=0;
    for (int i=2; i<=n; i+=2)
        if (a[i]<=a[i+1] || a[i]<=a[i-1])
        {
            ans=ans+max(a[i-1],a[i+1])+1-a[i];
        }
    cout<<ans<<"\n";
}

void EvenSolve()
{
    ///2
    dp[1]=oo;
    for (int i=2; i<n; i++)
    {
        dp[i]=0;
    }
    dp[2]=0;
    if (a[2]<=a[1] || a[2]<=a[3])
    {
        dp[2]=max(a[1],a[3])+1-a[2];
    }
    ///3
    dp[3]=0;
    if (a[3]<=a[2] || a[3]<=a[4])
    {
        dp[3]=max(a[2],a[4])+1-a[3];
    }
    for (int i=4; i<n; i++)
    {
        if (i%2==0)
        {
            if (a[i]<=a[i-1] || a[i]<=a[i+1])
            {
                dp[i]=max(a[i-1],a[i+1])+1-a[i];
            }
            dp[i]=dp[i]+dp[i-2];
        }
        else
        {
//            cout<<i<<endl;
            if (a[i]<=a[i-1] || a[i]<=a[i+1])
            {
//                cout<<i<<endl;
                dp[i]=max(a[i-1],a[i+1])+1-a[i];
            }
//            cout<<dp[i]<<endl;
            dp[i]=dp[i]+min(dp[i-2],dp[i-3]);
        }
    }
//    for (int i=1; i<=n; i++)
//        cout<<dp[i]<<' ';
//    cout<<endl;
    cout<<min(dp[n-1],dp[n-2])<<"\n";
}

int main()
{
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout); 

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Test;
    cin>>Test;
    for (int TestCase=1; TestCase<=Test; TestCase++)
    {
        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        if (n%2==1)
        {
            OddSolve();
        }
        else
            EvenSolve();
    }

    return 0;
}

