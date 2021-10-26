    #include<bits/stdc++.h>
    using namespace std;

    int main(){
    //freopen("coto.inp","r",stdin);
    //freopen("coto.out","w",stdout);
    int test;
    cin>>test;
    for (int t=1;t<=test;t++){
        long long s=1,a;
        int n;
        cin>>n;
        for (int i=1;i<=n-1;i++) {
            cin>>a;
            s=(s*a)%(1234567);
        }
        cout<<s;
    }
    }
