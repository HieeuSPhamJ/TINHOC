#include<bits/stdc++.h>
using namespace std;

int n,s=0;
int a[31];
int s1=0;
int ok[31];

void dayso(int i){
    for (int j=1;j<=n;j++){
    if (ok[j]==0){
        s1+=a[j]; ok[i]=1;
        if (s1==s){
            cout<<"BANG"<<endl; exit(0);
        }
        else  dayso(i+1);
        ok[j]=0;
        s1-=a[j];

    }
    }
}

int main(){
    cin>>n;
    memse(ok,0,size(ok));
    for (int i=1;i<=n;i++){
        cin>>a[i]; s+=a[i];
    }
    s/=2;
    dayso(1);
    cout<<"KHONG BANG";
return 0;
}
