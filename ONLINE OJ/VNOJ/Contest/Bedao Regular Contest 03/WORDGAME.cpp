#include<bits/stdc++.h>
using namespace std;

map <string,bool> checkMap;


int main(){
    int n;
    cin>>n;
    string inp;
    cin>>inp;
    char lastletter=inp[inp.length()-1];
    for (int i=2;i<=n;i++){
        cin>>inp;
        // cout<<(lastletter==inp[0])<<endl;
        if (checkMap[inp]!=1 and lastletter==inp[0]){
            checkMap[inp]==1;
            lastletter=inp[inp.length()-1];
        }
        else{
            cout<<"NO"<<endl;
            cout<<i;
            return 0;
        }
    }
    cout<<"YES";
return 0;
}