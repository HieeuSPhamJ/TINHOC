#include<bits/stdc++.h>
using namespace std;

int n;
long long a[200005];
long long sum[200005];

// void smallDataSet(){
//     for (int i=1;i<=n;i++){
//         cin>>a[i];
//         // cout<<a[i];
//     }
//     long long sum=0;
//     for (int j=2;j<=n;j++){
//         for (int i=1;i<j;i++){
//             sum+=a[i]*a[j];
//             cout<<i<<' '<<j<<endl;
//         }
//     }
//     cout<<sum;
// }

void bigDataSet(){
    sum[0]=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        // cout<<a[i];
    }
    long long ans=0;
    for (int i=1;i<=n;i++){
        ans+=(a[i]*(sum[i-1]));
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("WC5.INP","r",stdin);
    freopen("WC5.OUT","w",stdout);
    int test;
    cin>>test;
    while(test--){
        cin>>n;
        // if(n<=200){
        //     smallDataSet();
        // }
        // else{
        //     smallDataSet();
        // }
        bigDataSet();
        cout<<endl;
    }


}