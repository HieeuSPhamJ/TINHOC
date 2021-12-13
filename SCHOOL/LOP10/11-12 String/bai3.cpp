#include<bits/stdc++.h>
using namespace std;

int main(){
    stack <char> tempStack;
    map <char,char> store;
    store[')']='(';
    store[']']='[';
    store['}']='{';
    store['>']='<';
    
    string s;
    cin>>s;
    for (int i=0;i<int(s.length());i++){
        char inp=s[i];
        if (inp=='(' or inp=='{' or inp=='[' or inp=='<'){
            tempStack.push(inp);
        }
        else {
            cout<<inp<<' '<<tempStack.top()<<endl;
            if (inp!=store[tempStack.top()]){
                cout<<"BAD";
                return 0;
            }
            else {
                tempStack.pop();
            }
        }
    }
    cout<<"GUD";
    return 0;
}
