#include <bits/stdc++.h>
using namespace std;

#define int long long
int N=1e9+7;
#undef int

int main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    #define int long long
    int n; cin>>n;
    int a[n];
    vector<int>l(n),r(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        l[i]=a[i]+i;
        r[i]=a[i]+n-i-1;
    }
    for(int i=1,j=n-2;i<n,j>=0;i++,j--){
       r[i]=max(r[i-1],r[i]);
       l[j]=max(l[j+1],l[j]);
    }
    // for(int i=0;i<n;i++){
    //     cout<<l[i]<<" "<<r[i]<<"\n";
    // }
    // cout<<"\n";
    int ans=INT_MAX;
    if(n!=1){
        for(int i=0;i<n;i++){
            int ll,rr;
            if(i!=0 && i!=n-1){
                ll=r[i-1];
                rr=l[i+1];
            }
            else if(i==0){
                ll=0;
                rr=l[i+1];
            }
            else{
                ll=r[i-1];
                rr=0;
            }
            ans=min(ans,max(a[i],max(ll,rr)));
        }
        cout<<ans;
    }
    else cout<<a[0];
}