#include<bits/stdc++.h>
using namespace std;

int main(){
int ans[100];
memset(ans,0,sizeof(ans));
int a,b,c;
cin>>a>>b>>c;
for (int i=1;i<=a;i++)
    for (int j=1;j<=b;j++)
        for (int e=1;e<=c;e++)
            ans[i+j+e]++;
int ansout=0;
int m=0;
for (int i=90;i>1;i--){
    //cout<<ans[i];
    if(m<=ans[i]){
        m=ans[i];
        ansout=i;
    }
}
cout<<ansout;
return 0;
}
