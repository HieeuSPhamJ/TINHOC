#include<bits/stdc++.h>
using namespace std;

int a[100005];

bool cmp(int a,int b){
    return a>b;
}


int main(){
    freopen("CATGO.INP","r",stdin);
    freopen("CATGO.OUT","w",stdout);
    int n,l;
    cin>>n>>l;
    int count=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        count+=(a[i]>l);
    }
    if (count==0){
        cout<<-1;
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    cout<<count<<endl;
    for (int i=1;i<=n;i++){
        if (a[i]>l){
            cout<<a[i]<<' ';
        }
        else {
            break;
        }
    }
    
    return 0;
}