#include<bits/stdc++.h>
using namespace std;


int Nguoc(int n){
    int ans=0;
    ans+=(n%10);
    n/=10;
    //cout<<ans<<' '<<n<<endl;
    while(n!=0){
        ans=ans*10+(n%10);
        n/=10;
        //cout<<ans<<' '<<n<<endl;
    }
return ans;
}


int main(){
    freopen("NGUOC.inp","r",stdin);
    freopen("NGUOC.out","w",stdout);
    int k,n;
    while (cin>>k>>n){
        int num=k;
        cout<<num<<' ';
        for (int i=2;i<=n;i++){
            num+=k;
            num=Nguoc(num);
            cout<<num<<' ';

        }
    cout<<endl;
    }
return 0;
}
