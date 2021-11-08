#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n/2;i++){
        for (int e=i+1;e<=n-1;e++){
            int j=n-i-e;
            if (i<e and e<j){
                cout<<i<<' '<<e<<' '<<j<<endl;
            }
        }
    }
    return 0; 
}