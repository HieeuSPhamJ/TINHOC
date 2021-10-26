#include<bits/stdc++.h>
using namespace std;

int main (){
int n;
cin>>n;
int mi,ma;
int smi=0,sma=0;
cin>>mi;
ma=mi;
for (int i=1;i<n;i++){
    int inp;
    cin>>inp;
    if (inp>ma){
        ma=inp;
        sma++;
    }
    if (inp<mi){
        mi=inp;
        smi++;
    }
}
cout<<sma<<' '<<smi;

return 0;
}
