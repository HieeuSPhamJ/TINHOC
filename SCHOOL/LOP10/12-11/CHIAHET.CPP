#include<bits/stdc++.h>
using namespace std;

int a[1003];


int main(){
    freopen("CHIAHET.INP","r",stdin);
    freopen("CHIAHET.OUT","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxCount=0;
    int maxTemp=0;
    for (int i=1;i<=n;i++){
        int count=0;
        for (int e=1;e<=n;e++){
            if (a[e]%a[i]==0){
                count++;
            }
        }
        if (maxCount<count){
            maxCount=count;
            maxTemp=a[i];
        }
    }

    cout<<maxTemp<<' '<<maxCount-1;
    return 0;
}