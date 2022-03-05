#include<bits/stdc++.h>
using namespace std;
 
string s;
stack <char> myStack;

int main(){
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++){
        if (s[i] == ')' and !myStack.empty()){
            if (myStack.top() == '('){
                myStack.pop();
            }
            else{
                myStack.push(')');
            }

        }
        else{
            myStack.push(s[i]);
        }
    }
    stack <char> tempStack = myStack;
    stack <char> tempTempStack;
    // while(!tempStack.empty()){
    //     tempTempStack.push(tempStack.top());
    //     tempStack.pop();
    // }
    // while(!tempTempStack.empty()){
    //     cout << tempTempStack.top();
    //     tempTempStack.pop();
    // }
    
    int newLen = myStack.size();
    int count = 0;
    while(!myStack.empty() and myStack.top() == '('){
        count++;
        myStack.pop();
    }
    cout << newLen / 2 + count % 2;
    return 0;
}