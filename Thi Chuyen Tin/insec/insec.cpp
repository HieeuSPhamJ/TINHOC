#include<bits/stdc++.h>
using namespace std;

int check(int x){
while (x!=0){
    //cout<<x%10<<endl;
    if (x%10==4) return 0;
    x=x/10;
}
return 1;
}

int main(){
int n;
cin>>n;
int a=n/2,b=n-a;
//cout<<check(n)<<endl;
while (!check(a) or !check(b)){ a--; b++; }
cout<<a<<' '<<b;
return 0;
}
