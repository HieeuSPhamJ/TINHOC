#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[502];
int b[502];
int t[502];
int ans=-1;


void backTracking(int sum,int i,int time){
    // cout<<sum<<' '<<i<<' '<<time<<' '<<endl;

    if (i==n){
        if ((ans==-1 or ans>time) and sum<=m){
            ans=time;
        }
    }
    else {
        backTracking(sum+a[i],i+1,time);
        backTracking(sum+b[i],i+1,time+t[i]);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>t[i];
        // ans+=t[i];
    }
    backTracking(0,0,0);
    cout<<ans;
    return 0;
}
