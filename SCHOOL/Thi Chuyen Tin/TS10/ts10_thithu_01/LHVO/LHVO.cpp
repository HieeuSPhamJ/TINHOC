#include<bits/stdc++.h>
using namespace std;

int a[15]={0,1,2,1,0,1,0,1,1,0,1,0,1,1,2};
int main(){
    freopen("lhvo.inp","r",stdin);
    freopen("lhvo.out","w",stdout);
    int d,m,y;
    cin>>d>>m>>y;
    if (m==6) m++;
    //if (m==12) { cout<<2<<' '<<1<<y+1; return 0; }
    //if (a[m]!=a[m+1] and m!=2) { cout<<2<<' '<<m+1<<y; return 0; }
    //else if (m==2 and y%4==0 and y%100!=0 ) { cout<<2<<' '<<m+1<<y; return 0; }
    if (m==7) { cout<<2<<' '<<m+2<<' '<<y; return 0; }
    if (m==2 and y%4==0 and y%100!=0) { cout<<2<<' '<<m+1<<' '<<y; return 0; }
    else if (m==2) { cout<<2<<' '<<m+2<<' '<<y; return 0; }
    if (m==12) { cout<<2<<' '<<1<<' '<<y+1; return 0; }
    if (m==11) { cout<<2<<' '<<1<<' '<<y+1; return 0; }
    if (a[m]==1) { cout<<2<<' '<<m+1<<' '<<y; return 0; }
    if (a[m]==0) { cout<<2<<' '<<m+2<<' '<<y; return 0; }

return 0;
}
