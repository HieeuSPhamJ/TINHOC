#include<bits/stdc++.h>
using namespace std;

string n;

void Solve(){
    vector <int> ans;
    int temp[1000];
    int length=n.length()-1;
    temp[length]=1;
    for (int i=length;i>=0;i--){
        int numNow=n[i]-'0';
        numNow-=temp[i];
        temp[i-1]=(numNow<0);
        if (numNow<0){
            numNow+=10;
        }
        ans.push_back(abs(numNow));
        // cout<<temp[i]<<' '<<temp[i-1]<<' '<<numNow<<endl;
    }
    bool check=false;
    for (int i=ans.size()-1;i>=0;i--){
        if (check==false and ans[i]!=0){
            check=true;
        }
        if (check==true){
            cout<<ans[i];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("WC2.INP","r",stdin);
    freopen("WC2.OUT","w",stdout);
    int test;
    cin>>test;
    while(test--){
        cin>>n;
        if (n=="1") cout<<0;
        else{
            Solve();
        }
        cout<<endl;
    }


}