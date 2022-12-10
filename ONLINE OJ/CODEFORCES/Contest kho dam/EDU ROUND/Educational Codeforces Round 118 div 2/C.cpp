#include<bits/stdc++.h>
using namespace std;

long long a[101];

void solve(){
    int n;
    cin>>n;
    long long h;
    long long sum=0;
    cin>>h;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    long long left=1;
    long long right=1e18;
    while (left<=right){
        long long m=(left+right)/2;
        long long sum=0;
        for (int i=1;i<n;i++){
            sum+=min(m,a[i]-a[i-1]);
        }
        sum+=m;
        if (sum>=h)right=m-1;
        else left=m+1;
    }
    long long ans=right;
    
    for (int i=1;i<n;i++){
        sum+=min(ans,a[i]-a[i-1]);
    }
    sum+=ans;
    if (sum<h)ans++;
    cout<<ans<<endl;
}
int main(){

    int test;
    cin>>test;
    for (int i=0;i<test;i++){
        solve();
    }
}
