#include <bits/stdc++.h>
using namespace std;
long long test_case,tt,f[100][200][200][3],newsumx,newsumy,ans,k,dx,newrem;
bool nto[1000];
string n;
int main()
{
    cin>>n;
    f[0][0][0][0]=1;
    n='0'+n;
    n=n+'0';
    for (int i=2;i<=135;i++)
    {
        if (nto[i]==true)
        {
          for (int j=2*i;j<=135;j+=i)
          {
            nto[j]=false;
          }
        }
        
    }
    for (int i = 1; i <= 20; i++){
        cout << nto[i] << ' ';
    }
    reverse(n.begin(),n.end());
    f[0][0][0][0]=1;
    for (int i=1;i<n.size()-1;i++)
    {
        for (int sumx=0;sumx<=135;sumx++)
        {
            for (int sumy=0;sumy<=135;sumy++)
            {
                for (int rem=0;rem<=2;rem++)
                {
                    if (f[i][sumx][sumy][rem]>0)
                    {
                        for (int dy=0;dy<=9;dy++)
                        {
                            for (int tam=0;tam<=2;tam++)
                            {
                                dx=(10*tam+n[i+1]-'0')-(2*dy+rem);
                                if (dx<0)
                                {
                                    continue;
                                }
                                newsumx=sumx+dx;
                                newsumy=sumx+dy;
                                newrem=(dx+dy*2+rem)/10;
                                f[i+1][newsumx][newsumy][newrem]+=f[i][sumx][sumy][rem];
                            }
                        }
                    }
                }
            }
        }
    }
    ans=0;
    for (int sumx=1;sumx<=135;sumx++)
    {
        for (int sumy=1;sumy<=135;sumy++)
        {
            if (nto[sumx] && nto[sumy])
            {
                ans=ans+f[n.size()-1][sumx][sumy][0];
            }
        }
    }
    cout<<ans<<endl;
}