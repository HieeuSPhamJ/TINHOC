#include<bits/stdc++.h>
using namespace std;

stack <int> myStack;

int main(){
    freopen("NGOAC.INP", "r", stdin);
    freopen("NGOAC.OUT", "w", stdout);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        char inp = s[i];
        if (inp == '('){
            myStack.push(i);
        }
        else{
            cout << myStack.top() + 1 << ' ' << i + 1 << endl; 
            myStack.pop();
        }
    }

    return 0;
}