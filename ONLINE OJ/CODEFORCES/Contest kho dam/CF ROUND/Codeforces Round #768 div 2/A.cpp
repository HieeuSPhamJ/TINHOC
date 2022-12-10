#include<bits/stdc++.h>
using namespace std;




int main(){
    int test;
    cin >> test;
    while(test--){
        priority_queue <int> myHeap;
        int n;
        cin >> n;
        int m1 = 0, m2 = 0;
        for (int i = 1; i <= 2 * n; i++){
            int inp;
            cin >> inp;
            myHeap.push(inp);
        
        }
        m1 = myHeap.top();
        myHeap.pop();
        m2 = myHeap.top();;
        cout << m1 * m2;
        cout << endl;
    }



    return 0;
}