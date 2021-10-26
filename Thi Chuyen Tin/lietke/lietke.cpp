#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[10];

void lietke(int i){
for (int j=a[i-1]+1;j<=n-k+i;j++){
        a[i]=j;
        if (i==k){
            for (int e=1;e<=k;e++)
                cout<<a[e]<<' ';
            cout<<endl;
        }
        else lietke(i+1);
        a[i]=0;
}
}

int main (){
cin>>n>>k;
lietke(1);
return 0;
}
