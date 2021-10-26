#include <bits/stdc++.h>
#define Nmax 10000001
using namespace std;

int n,m,a[10000010],b[10000010],ok[10000010];

void SNT(){
    fill(ok+0,ok+10000010+1,1);
    ok[1]=0;
    for (int x=2;x<=sqrt(10000010);x++){
    if (ok[x])
        for (int i=2;x*i<=10000010;i++){
            ok[x*i]=0;
        }
    }
}
void PHANTICH(int ar[],int x){
    for (int i=2;x>1;i++){
            if (ok[x]) {ar[x]++; return;}
        while (x%i==0){
            ar[i]++;
            x/=i;
        }
    }
}

int main(){
    //PHANTICH(1,4); cout<<a[2];
    SNT();
    //for (int i=1;i<=10;i++) if (ok[i]==1) cout<<i;
    memset (a,0,sizeof(a));
    memset (b,0,sizeof(b));
    cin>>n>>m;
    for (int i=1;i<=n;i++) { cin>>a[0]; PHANTICH(a,a[0]); }
    for (int i=1;i<=m;i++) { cin>>b[0]; PHANTICH(b,b[0]); }
    for (int i=1;i<=10000010;i++){
        if (a[i]!=b[i]) {cout<<0; break;}
        if (i==10000010) cout<<1;
    }
    cout<<endl;
    for (int i=1;i<=10;i++) cout<<a[i]<<' ';
    cout<<endl;
    for (int i=1;i<=10;i++) cout<<b[i]<<' ';
return 0;
}
