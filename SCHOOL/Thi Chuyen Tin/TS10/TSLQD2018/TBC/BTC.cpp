#include<bits/stdc++.h>
using namespace std;
long long k;
double s=0;
int n=0;

void Locso(){
while (k>0){
    s+=k%10;
    k/=10;
    n++;
}
}

int main (){
    cin>>k;
    Locso();
    cout<<fixed<<setprecision(2)<<s/n;
return 0;
}
