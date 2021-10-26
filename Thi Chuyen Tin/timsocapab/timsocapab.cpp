#include<bits/stdc++.h>
using namespace std;
const int M=sqrt(1000000000)+10;
int a[M+10];
int b[M+10];
int SNTe=1;
void LocSNT(){
int x=1;
for (int i=2;i*i<=M;i++){
    if (b[i]==1){
        for (int e=2;e*i<=M;e++){
            b[i*e]=0;

        }
        a[x++]=i;;
    }
}

}

int Check(int n){
    if (n==1) return 0;
    for(int i=2;i<sqrt(n);i++){
        //cout<<i;
        if (n%a[i]==0) return 0;
    }
    return 1;
}

int main(){
    fill(a+2,a+M+1,1);
    int n,m;
    cin>>n>>m;
    LocSNT();
    for (int i=1;i<=m;i++) cout<<b[i]<<' '; cout<<endl;
    int ans=0;
    int x=-1;
    for (int i=n;i<=m;i++){
        if (Check(i)){
            if (i-2==x) {
                ans++;
                cout<<i<<endl;
            }
            x=i;

        }
    }
    cout<<ans;

return 0;
}
