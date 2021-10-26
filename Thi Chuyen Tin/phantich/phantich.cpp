#include<bits/stdc++.h>
using namespace std;
int n,d=0,s=0;
int a[200];
void phantich(int i){
for (int j=a[i-1];j<=n-s;j++){
        a[i]=j;
        s+=j;
        if (s==n){
                d++;
            //for (int e=1;e<=i;e++) cout<<a[e]<<" ";          cout<<endl;
        }
        else phantich(i+1);
    a[i]=0;
    s-=j;
}
}

int main (){
memset(a,0,sizeof(a));
a[0]=1;
cin>>n;
phantich(1);
cout<<d;
return 0;
}
