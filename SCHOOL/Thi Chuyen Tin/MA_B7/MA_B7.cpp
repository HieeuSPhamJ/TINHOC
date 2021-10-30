#include<bits/stdc++.h>
using namespace std;

int main(){
long long n0;
cin>>n0;
double n=sqrt(n0);
for (int b=1;1;b++){
    double a=n/sqrt(b);
    //cout<<'#'<<b<<' '<<a<<' '<<b<<endl;
    if (int(a)==a){ cout<<a<<' '<<b; break; }

}
return 0;
}
