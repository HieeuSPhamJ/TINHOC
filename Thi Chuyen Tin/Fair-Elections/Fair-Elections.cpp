#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
return a>b;
}

int main(){
    int t,n,m,a[1010],b[1010];
    cin>>t;
    for (int test=1;test<=t;test++){
        cin>>n>>m;
        int as=0,bs=0;
        for (int i=1;i<=n;i++){
            cin>>a[i]; as+=a[i];
        }
        sort (a+1,a+n+1);
        //for (int i=1;i<=n;i++)  cout<<a[i];
        for (int i=1;i<=m;i++){
            cin>>b[i]; bs+=b[i];
        }
        sort (b+1,b+m+1,cmp);
        //for (int i=1;i<=m;i++) cout<<b[i];
        if (as>bs) cout<<0<<endl;
        else {
            for (int i=1;i<=min(n,m);i++){
                as=as-a[i]+b[i];
                bs=bs-b[i]+a[i];
                if (as>bs) {cout<<i<<endl; break;}
            }
            if (as<=bs) cout<<-1<<endl;
        }
    }

    return 0;
}
