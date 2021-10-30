#include<bits/stdc++.h>
using namespace std;

long long tp(int x1,int x2,int x3){
    long long n=0;
    for (int i=0;i<=x3-1;i++) n+=((long long)1<<i);
    for (int i=x2+x3;i<=x2+x3+x1-1;i++) n+=((long long)1<<i);
    return n;
}

int main(){
long long a,b;
int s=0;
cin>>a>>b;
for (int x1=1;x1<=60;x1++)
    for (int x2=1;x2<=60;x2++)
        for (int x3=1;x3<=60;x3++)
        if(x1+x2+x3<=60)
        {
            long long t=( ((long long)1<<(x1+x2+x3))-1 - ((long long)1<<(x2+x3))+1 + ((long long)1<<x3)-1 );
            //long long t=tp(x1,x2,x3);
            if(a<=t and t<=b){
                s++;
                cout<<t<<' ';
            }
        }

cout<<endl<<s;
//cout<<(1<<5)-1-(1<<4)+1+(1<<2)-1;
return 0;
}
