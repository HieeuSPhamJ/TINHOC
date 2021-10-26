#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("shaa.inp","r",stdin);
freopen("shaa.out","w",stdout);
int t;
cin>>t;
for (int e=1;e<=t;e++){
    int n;
    long long a[100010];
    int b[100010];
    a[0]=0;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>b[i];
        a[i]=a[i-1]+b[i];
    }
    int ans=0;
    //cout<<b[2];
    for (int i=1;i<=n;i++){
        //cout<<b[i];
        if (a[i]-b[i]==a[n]-a[i]){
            ans=1;
            break;
        }
    }
    if (ans) cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

}
