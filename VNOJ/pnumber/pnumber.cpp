#include<bits/stdc++.h>
using namespace std;

int ans[200010];

void SNT(){
    for (int i=2;i*i<=200000;i++){
        if (ans[i]==0)
            for (int e=2;e*i<=200000;e++)
                ans[e*i]=1;
    }

}

int main(){
    memset(ans,0,sizeof(ans));
    int a,b;
    cin>>a>>b;
    SNT();
    ans[1]=1;
    for(int i=a;i<=b;i++){
        if (ans[i]==0){
            cout<<i<<endl;
        }
    }
return 0;
}
