#include<bits/stdc++.h>
using namespace std;

long long a[10004];
long long t[10004];
int n;


bool check(long long time){
    // cout<<time<<endl;
    bool mapcheck[10004]={false};
    for (int i=1;i<=n;i++){
        for (int e=0;e<=time/t[i];e++){
            if (a[i]+e<=n){
                mapcheck[a[i]+e]=1;
            }
            if (a[i]-e>0){
                mapcheck[a[i]-e]=1;
            }
        }
        // for (int i=1;i<=n;i++){
        //     cout<<mapcheck[i];
        // }
        // cout<<endl;
    }
    for (int i=1;i<=n;i++){
        if (!mapcheck[i]){
            return 0;
        }
    }
    return 1;

}

int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>t[i];
    }
    long long left=1;
    long long right=1e8+10;
    while(left<=right){
        int mid=(left+right)/2;
        if (check(mid)){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
        // cout<<mid<<endl;
    }
    cout<<left;
}



