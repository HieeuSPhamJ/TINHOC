#include<bits/stdc++.h>
using namespace std;
int n;
int inp[100010];

bool cmp(int a,int b){
return a>b;
}

int main (){
    //freopen("tamgiac.inp","r",stdin);
    //freopen("tamgiac.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>inp[i];
    sort (inp+1,inp+n+1,cmp);
    for (int i=3;i<=n;i++){
        int a=inp[i],b=inp[i-1],c=inp[i-2];
        if (a+b>c && a+c>b && c+b>a){
            cout<<c<<' '<<b<<' '<<a;
            exit(1);
        }

    }
    cout<<-1;
return 0;
}
