#include <bits/stdc++.h>
using namespace std;
int x[100];
int ok[100];
int check=1;
int n;
void lk(int i) {
    for (int j=1;j<=n;j++) {
        if (ok[j]==0) {
            x[i]=j; ok[j]=1;
            if (i==n) {
                for (int e=2;e<=n;e++)  if ( abs( x[e]-x[e-1] ) > n/2 )   check=0;
                if  (check==1) {    for (int e=1;e<=n;e++)  cout<<x[e]; cout<<endl; }
            }
            else    lk(i+1);
            ok[j]=0;
            check=1;
        }
    }
}

int main() {
memset(ok,0,sizeof(ok));
cin>>n;
lk(1);
return 0;
}
