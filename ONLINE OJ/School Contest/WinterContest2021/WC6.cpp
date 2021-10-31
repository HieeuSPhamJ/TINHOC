#include<bits/stdc++.h>
using namespace std;

int n;
int inp=0;
int missing=0;
int dup=0;
bool check[1000006];

void smallDataSet(){
    dup=0;
    missing=0;
    inp=0;
    memset(check,0,sizeof(check));
    for (int i=0;i<n;i++){
        cin>>inp;
        if (check[inp]==1){
            dup=inp;
        }  
        check[inp]=1;
    }
    for (int i=1;i<=n;i++){
        if (check[i]==0){
            missing=i;
        } 
    }
    cout<<dup<<' '<<missing;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("WC6.INP","r",stdin);
    freopen("WC6.OUT","w",stdout);
    int test;
    cin>>test;
    while(test--){
        cin>>n;
        smallDataSet();
        cout<<endl;
    }
}