#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        if (a+b<3 or (a+b<=3 and (a==1 or b==1))) cout<<"Yes";
        else cout<<"No";
        cout<<endl;
    }
return 0;
}
