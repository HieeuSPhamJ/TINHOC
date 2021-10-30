#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[11];
int b[11];
int c[11];
int n2=1,m2=1;

void Locso(){
while (n>0){
    a[n2]=n%10;
    n/=10;
    n2++;

}

while (m>0){
    b[m2]=m%10;
    m/=10;
    m2++;
}
}


int main(){
    cin>>n>>m;
    Locso();
    int e=1;
    for (int i=max(n2-1,m2-1);i>=1;i--) c[e++]=(a[i]+b[i])%10;
    //for (int i=1;i<=e-1;i++) cout<<c[i]<<' ';
    for (int i=1;i<=e-1;i++){
        if (c[i]!=0) {
            for (int j=i;j<=e-1;j++) cout<<c[j];
            exit(1);
        }
    }
    cout<<0;
return 0;
}
