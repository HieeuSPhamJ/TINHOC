#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int x[100010];
int y[100010];
int xlength=1,ylength=1;
void setup(){
    x[0]=0;
    y[0]=0;
    cin>>n>>m>>k;
    for (int i=1;i<=k;i++){
        int num1,num2;
        cin>>num1>>num2;
        if (!num1) {x[xlength]=num2; xlength++;}
        else {y[ylength]=num2; ylength++;}
    }
    sort(x,x+xlength);
    sort(y,y+ylength);
    x[0]=0; x[xlength]=n;
    y[0]=0; y[ylength]=m;
}

int ChieuDai(){
    int ans=0;
    for (int i=1;i<=xlength;i++){
        ans=max(ans,abs(x[i-1]-x[i]));
    }
    //cout<<"Dai: "<<ans<<endl;
    return ans;
}
int ChieuRong(){
    int ans=0;
    for (int i=1;i<=ylength;i++){
        ans=max(ans,abs(y[i-1]-y[i]));
    }
    //cout<<"Rong: "<<ans<<endl;
    return ans;
}

int main (){
    setup();
    //cout<<xlength<<ylength;
    //for (int i=0;i<=xlength;i++) cout<<x[i]<<' '; cout<<endl;
    //for (int i=0;i<=ylength;i++) cout<<y[i]<<' '; cout<<endl;
    cout<<min(ChieuDai(),ChieuRong());
return 0;
}
