#include<bits/stdc++.h>
using namespace std;

int main(){
    stack <char> ans;
    string s;
    getline(cin,s);
    int current=int(s.length())-1;
    for (int i=current;i>=0;i--){
        if (s[i]!=' '){
            ans.push(s[i]);
        }
        else{
            break;
        }
    }
    while(!ans.empty()){
        cout<<ans.top();
        ans.pop();
    }

    return 0;
}