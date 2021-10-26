#include<bits/stdc++.h>
using namespace std;

int main (){
int t;
cin>>t;
while(t--){
    long long TS;
    cin>>TS;
    if (TS%2!=0 or TS==1) cout<<TS/2;
    else{
        while (TS%2==0){
            TS/=2;
        }
        cout<<TS/2;
    }
    cout<<endl;
}

return 0;
}
