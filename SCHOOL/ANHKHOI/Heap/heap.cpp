#include<bits/stdc++.h>
using namespace std;

priority_queue <int,vector <int>,greater<int>> myHeap;

int main(){
    myHeap.push(3);
    myHeap.push(1);
    myHeap.push(2);
    cout<<myHeap.top()<<endl;
    myHeap.pop();
    cout<<myHeap.top();

    return 0;
}