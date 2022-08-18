#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        string inp;
        cin >> inp;
        stack (int) myStack;

        for (int i = 0; i < inp.length(); i++){
            if (s[i] == 'C'){
                myStack.push(12);
            }    
            else if (s[i] == 'H'){
                myStack.push(1);
            }
            else if (s[i] == 'O'){
                myStack.push(16);
            } 
            else if (s[i] == '('){
                myStack.push(0);
            } 
            else if (s[i] == ')'){
                myStack.push(1);
                int tempAns = 0;
                while(myStack.top() != 0){
                    myS
                }
            } 
        }
    }
    return 0;
}