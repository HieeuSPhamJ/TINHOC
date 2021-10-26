#include <bits/stdc++.h>
using namespace std;

int a[10];
int n;
int cc[50],cp[50],c[20];
int m=100,s=0;
int n2[10][10];

void chess (int i){
    for (int j=1;j<=n;j++) {
        if ( c[j]==0 and cc[(i-j)+10]==0 and cp[i+j]==0 and s+n2[i][j]<m) {
            a[i]=j; s=s+n2[i][j];
            c[j] = cc[(i-j)+10] = cp[i+j] = 1;
            if (i!=n) chess(i+1);
               else m=min(m,s);
            s=s-n2[i][j];
            a[i] = c[j] = cc[(i-j)+10] = cp[i+j] = 0;
        }
    }
}

int main () {
memset (c,0,sizeof(c));    memset (cp,0,sizeof(cp));   memset (cc,0,sizeof(cc));
cin>>n;
for (int i=1;i<=n;i++)
    for (int e=1;e<=n;e++)
        cin>>n2[i][e];
chess(1);
cout<<m;
return 0;
}
