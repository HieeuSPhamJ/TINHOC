#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000010];
int m=0;

int main (){
    freopen("STRONG.inp","r",stdin);
    freopen("STRONG.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    memset(a,0,sizeof(a));
    for (int i=1;i<=n;i++) {
        int inp;
        cin>>inp;
        a[inp]++;
        m=max(m,inp);
    }
    cout<<a[m];
return 0;
}
