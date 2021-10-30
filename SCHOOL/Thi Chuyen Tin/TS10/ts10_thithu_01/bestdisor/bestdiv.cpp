#include<bits/stdc++.h>
using namespace std;

int Locso(int n){
int s=0;
while (n>0){
    s+=n%10;
    n/=10;
}

return s;
}

int main (){
    freopen("bestdiv.inp","r",stdin);
    freopen("bestdiv.out","w",stdout);
    //cout<<Locso(99999);
    int n;
    cin>>n;
    int s=0;
    for (int i=1;i<=n/2;i++){
        if (n%i==0){
            if (Locso(i)>Locso(s))
                s=i;
        }
    }
    if (Locso(n)>Locso(s))
        s=n;
    cout<<s;

return 0;
}
