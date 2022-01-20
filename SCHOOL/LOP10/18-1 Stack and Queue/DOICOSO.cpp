#include<bits/stdc++.h>
using namespace std;



char temp[20]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
stack <char> myStack;


void Conv(long long n, int a){
    if (n > 0){
        myStack.push(temp[n % a]);
        Conv(n / a, a);
    }

}



int main(){
    freopen("DOICOSO.INP", "r", stdin);
    freopen("DOICOSO.OUT", "w", stdout);
    
    int n, a;
    cin >> n >> a;
    Conv(n, a);
    while(!myStack.empty()){
        cout << myStack.top();
        myStack.pop();
    }

    return 0;
}