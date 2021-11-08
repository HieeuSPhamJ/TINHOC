#include<bits/stdc++.h>
using namespace std;


priority_queue <long long> myHeap;


int main(){
    int n,m;
    cin>>m>>n;
    while(m--){
        int inp;
        cin>>inp;
        myHeap.push(inp);
    }
    long long profit=0;
    while(n--){
        profit+=myHeap.top();
        myHeap.push(myHeap.top()-1);
        myHeap.pop();
    }
    cout<<profit;

    return 0;
}