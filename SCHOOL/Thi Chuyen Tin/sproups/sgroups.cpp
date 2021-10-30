#include<bits/stdc++.h>
using namespace std;

int n,k;

int chiabo(int n){
double x=(n-k)/2;
double y=(n+k)/2;
cout<<x<<' '<<y<<endl;
if (int(x)+int(y)==n and x>=1 and y>=1) return chiabo(x)+chiabo(y);
return 1;
}

int main (){
cin>>n>>k;
cout<<chiabo(n);

return 0;
}
