#include<bits/stdc++.h>
using namespace std;

int l,r;
bool checkPrime[100005]={false};

void Eras(int n){
    checkPrime[1]=1;
    for (int i=2;i*i<=n;i++){
        if (checkPrime[i]==false){
            for (int e=2;e*i<=n;e++){
                checkPrime[i*e]=true;
            }
        }
    }
}

long long betterChecker(int n){
    long long ans=0;
    while(n>0){
        int tempI=n%10;
        ans+=tempI*tempI;
        n/=10;
    }
    return ans;
}

int main(){
    freopen("SNTTOTNHAT.INP","r",stdin);
    freopen("SNTTOTNHAT.OUT","w",stdout);
    cin>>l>>r;
    Eras(r);
    int ans=r+1;
    int tempCheck=-1;
    for (int i=r;i>=l;i--){
        if (!checkPrime[i]){
            // cout<<'!'<<ans<<' '<<i<<endl;
            if (tempCheck==-1){
                ans=i;
                tempCheck=1;
            }
            else{
                if (betterChecker(ans)<=betterChecker(i)){
                    ans=i;
                    // cout<<betterChecker(ans)<<' '<<betterChecker(i)<<endl;
                }
            }
        }
    }
    cout<<ans;


    return 0;
}