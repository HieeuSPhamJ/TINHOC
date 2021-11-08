#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    // int sum=0;
    // int bottle=a/b;
    // int temp=a%b;
    // while(bottle>0){
    //     sum+=bottle;
    //     temp+=temp*c;
    //     bottle=temp/b;
    //     // cout<<sum;
    // }
    cout<<a/(b-c);
    return 0; 
}