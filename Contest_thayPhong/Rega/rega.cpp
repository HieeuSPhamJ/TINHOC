#include<bits/stdc++.h>
using namespace std;

int main (){
int test;
cin>>test;
while(test--){
    int n,k;
    int a[100010];
    cin>>n>>k;
    int e=n-1;
    for (int i=1;i<=n;i+=2){
        a[i]=e;
        e--;
    }
    e=0;
    for (int i=2;i<=n;i+=2){
        a[i]=e;
        e++;
    }
    for (int i=1;i<=n;i++){
        if (a[i]==k) cout<<i-1<<endl;
    }

}

return 0;
}
