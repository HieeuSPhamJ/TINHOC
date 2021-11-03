#include<bits/stdc++.h>
using namespace std;

string s1;
string s2;
string s;
unsigned long long mod=1000000007;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("WC4.INP","r",stdin);
    freopen("WC4.OUT","w",stdout);
    int test;
    cin>>test;
    while(test--){
        cin>>s1>>s2>>s;
        unsigned long long ans=1;
        for (int i=1;i<=(int)s1.length();i++){
            ans=((ans%mod)*(25%mod))%mod;
        }
        cout<<ans;
        cout<<endl;
    }
}