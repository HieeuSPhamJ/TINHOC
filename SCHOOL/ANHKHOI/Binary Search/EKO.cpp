#include<bits/stdc++.h>
using namespace std;

const long long maxN=1e6+10;

long long a[maxN];
long long n;

long long cutWood(long long high){
    long long woodLength=0;
    for (long long i=1;i<=n;i++){
        if (a[i]>high){
            woodLength+=a[i]-high;
        }
        
    }
    return woodLength;
}

void binarySearch(long long left,long long right,long long high){
    long long ans=0;
    while(left<=right){
        long long mid=(left+right)/2;
        // cout<<left<<' '<<right<<endl;

        if (cutWood(mid)>=high){
            ans=max(ans,mid);
        }
        if (cutWood(mid)>high){
            left=mid+1;
        }
        else{
            right=mid-1;
        }

        // cout<<mid<<' '<<cutWood(mid)<<endl;
        // cout<<"-------------"<<endl;
    }
    cout<<ans;

}


int main(){
    long long h;
    cin>>n>>h;
    long long maxa=0;
    for (long long i=1;i<=n;i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    binarySearch(1,maxa,h);

    return 0;
}