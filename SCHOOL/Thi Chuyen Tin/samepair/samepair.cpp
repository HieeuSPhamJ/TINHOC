#include<bits/stdc++.h>
#define m 1000010
using namespace std;

int l,r;
int s=0,a[m],b[m],ok[m];

void SNT(){
    fill(ok+0,ok+m+1,1);
    ok[1]=0;
    for (int x=2;x<=sqrt(m);x++){
    if (ok[x])
        for (int i=2;x*i<=m;i++){
            ok[x*i]=0;
        }
    }
}
void PT(int ar[],int x){
    ar[0]=0;
    for (int i=2;x>1;i++){
        if (ok[x]) {ar[++ar[0]]=x; return;}
        if(x%i==0) ar[0]++;
        while (x%i==0){
            ar[ar[0]]=x;
            x/=i;
        }
    }
}

int check(int ax, int bx){
PT(a,ax);
PT(b,bx);
if (a[0]!=b[0]) return 0;
for (int i=1;i<=a[0];i++) if (a[i]!=b[i]) return 0;
return 1;
}

int main(){
//freopen("samepair.inp","r",stdin);
//freopen("samepair.out","w",stdout);
SNT();
cin>>l>>r;
PT(a,9);
//for(int i=1;i<=a[0];i++) cout<<a[i]<<" ";cout<<endl;
for (int ax=l;ax<r;ax++){
    for (int bx=ax+1;bx<=r;bx++)
    {
        //if(check(ax,bx)) cout<<ax<<" "<<bx<<endl;
        s+=check(ax,bx);
    }
}
cout<<s;

return 0;
}
