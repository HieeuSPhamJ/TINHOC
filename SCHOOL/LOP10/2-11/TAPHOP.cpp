#include<bits/stdc++.h>
using namespace std;

int a[110]={false};
int b[110]={false};
int c[110]={false};

int main(){
    freopen("TAPHOP.INP","r",stdin);
    freopen("TAPHOP.OUT","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int inp;
        cin>>inp;
        a[inp]=true;
    }
    for(int i=1;i<=m;i++){
        int inp;
        cin>>inp;
        b[inp]=true;
    }
    for (int i=1;i<=110;i++){
        if (a[i] or b[i]){
            cout<<i<<' ';
        }
    }
    cout<<endl;
    for (int i=1;i<=110;i++){
        if (a[i] and b[i]){
            cout<<i<<' ';
            c[i]=true;
        }
    }
    cout<<endl;
    for (int i=1;i<=110;i++){
        if (a[i] and !b[i]){
            cout<<i<<' ';
        }
    }
    cout<<endl;
    for (int i=1;i<=110;i++){
        if (a[i] and !b[i]){
            cout<<i<<' ';
        }
    }
    cout<<endl;


return 0;
}
