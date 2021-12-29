#include<bits/stdc++.h>
using namespace std;

long long wide=0;
long long h[2000005];
long long w[2000005];
priority_queue <long long> myHeap;

int main(){
    freopen("PHOTO.INP","r",stdin);
    freopen("PHOTO.OUT","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>w[i]>>h[i];
        wide+=w[i];
        myHeap.push(h[i]);
    }
    long long h1=myHeap.top(); myHeap.pop();
    long long h2=myHeap.top();
    // cout<<h1<<' '<<h2<<endl;
    for (int i=1;i<=n;i++){
        long long high=h1;
        if (high==h[i]){
            high=h2;
        }
        // cout<<wide-w[i]<<' '<<high<<endl;
        cout<<(wide-w[i])*high<<' ';
        // cout<<endl;
    }



    return 0;
}