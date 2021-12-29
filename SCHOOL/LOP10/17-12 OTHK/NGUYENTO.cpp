#include<bits/stdc++.h>
using namespace std;

const int maxN=10000007;

bool check[maxN]={false};

void Eras(){
    check[0]=check[1]=1;
    for (int i=2;i*i<=maxN;i++){
        if (check[i]==0){
            for (int e=i*i;e<=maxN;e+=i) {
                check[e]=1;
            }
        }
    }
}

int main(){
    freopen("NGUYENTO.INP","r",stdin);
    freopen("NGUYENTO.OUT","w",stdout);
    int n;
    cin>>n;
    Eras();
    int count=0;

    // for (int i=1;i<=100;i++){
    //     cout<<check[i]<<' ';
    // }

    for (int i=1;i<=n;i++){
        int inp;
        cin>>inp;
        count+=!check[inp];
        // cout<<!check[inp];
    }
    cout<<count;
    return 0;
}