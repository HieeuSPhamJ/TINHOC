#include<bits/stdc++.h>
using namespace std;

int n,m,k;
string s;
string tempString;

int calHamming(){
    int tempAns=1003;
    for (int i=0;i<n;i++){
        int tempDiff=0;
        for (int e=0;e<m;e++){
            tempDiff+=bool(s[(i+e)%n]!=tempString[e]);
        
        }
        tempAns=min(tempAns,tempDiff);
        // cout<<tempDiff<<' ';
    }
    // cout<<endl<<tempAns<<endl;
    return tempAns;
}

int main(){
    freopen("HAMMING.INP","r",stdin);
    freopen("HAMMING.OUT","w",stdout);
    cin>>n>>m>>k;
    cin>>s;
    int ans=1003;
    while(k--){
        cin>>tempString;
        ans=min(ans,calHamming());
    }
    cout<<ans;
    return 0;
}