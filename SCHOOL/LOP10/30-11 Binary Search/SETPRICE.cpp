#include<bits/stdc++.h>
using namespace std;

int a[100005];
int n;

int countWire(int k){
    int wireLength=0;
    for (int i=1;i<=n;i++){
        wireLength+=(a[i]/k);
    }
    return wireLength;
}

void binarySearch(int left,int right,int k){
    int ans=-1;
    while(left<=right){
        int mid=(left+right)/2;
        // cout<<left<<' '<<right<<endl;
        if (countWire(mid)>=k){
            ans=max(ans,mid);
        }
        if (countWire(mid)>=k){
            left=mid+1;
        }
        else {
            right=mid-1;
        }
        
        // cout<<mid<<' '<<countWire(mid)<<endl;
        // cout<<"______"<<endl;
    }
    cout<<ans;
}

int main(){
    freopen("SETPRICE.INP","r",stdin);
    freopen("SETPRICE.OUT","w",stdout);
    int k;
    cin>>n>>k;
    int maxa=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    binarySearch(1,maxa,k);
    // cout<<countWire(54270938);
    return 0;
}
