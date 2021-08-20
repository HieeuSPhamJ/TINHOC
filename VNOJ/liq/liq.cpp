#include<bits/stdc++.h>
using namespace std;

int rev(int a){
    int ans=0;
    while (a!=0){
        ans=ans*10+a%10;
        a=a/10;
    }

    return ans;
}

int main(){
    int a,b;
    cin>>a>>b;
    int ans = 0;
    for (int i=a;i<=b;i++){
        if (__gcd(i,rev(i))==1) ans++;
    }
    cout<<ans;
return 0;
}
