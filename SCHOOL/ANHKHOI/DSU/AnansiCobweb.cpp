#include<bits/stdc++.h>
using namespace std;

int root[10000000];

int checkRoot(int a){
    if (root[a]==a){
        return a;
    }
    else return root[a]=checkRoot(root[a]);
}


int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        root[i]=i;
    }
    while(m--){
        int test,a,b;
        cin>>test>>a>>b;
        if (test==1){
            if (checkRoot(a)!=checkRoot(b)){
                root[checkRoot(a)]=checkRoot(b);
            }
        }
        else{
            cout<<(checkRoot(a)==checkRoot(b))<<endl;
        }
        for (int i=1;i<=n;i++){
            cout<<root[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}