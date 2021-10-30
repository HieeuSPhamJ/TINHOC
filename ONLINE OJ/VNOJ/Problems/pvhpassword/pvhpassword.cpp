#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    int n;
    cin>>a>>n;
    int ans=0;
    for (int i=0;i<=a.length()-1;i++)
        //cout<<(int(a[i])-97+n)%26;
        ans+=(int(a[i])-97+n)%26;
    cout<<ans;
return 0;
}
