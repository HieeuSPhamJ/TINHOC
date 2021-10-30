#include<bits/stdc++.h>
using namespace std;

int power(int a,int b){
if (b==0) return 1;
int ans=1;
while (b--)
    ans*=a;
return ans;
}

int main (){
int a,b,x;
cin>>a>>b>>x;
int ab=power(a,b);
int ans1=ab/x*x;
int ans2=(ab/x+1)*x;
if (abs(ans1-ab)>abs(ans2-ab)) cout<<ans2;
else cout<<ans1;
//cout<<endl<<ans1<<' '<<ans2;
return 0;
}
