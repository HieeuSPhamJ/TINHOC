#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("FINDSEAT.INP","r",stdin);
    freopen("FINDSEAT.OUT","w",stdout);
    long long n,m,t;
    cin>>n>>m>>t;
    if (n*m>=t){
        if (t%m==0){
            cout<<t/m;
        }
        else{
            cout<<(t/m)+1;
        }
        cout<<' ';
        if (t%m==0){
            cout<<m;
        }
        else cout<<t%m;
    }
    else cout<<-1;
    return 0;
}
