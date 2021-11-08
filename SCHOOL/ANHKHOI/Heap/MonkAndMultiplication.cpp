#include<bits/stdc++.h>
using namespace std;


priority_queue <long long> myHeap;

int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        long long inp;
        cin>>inp;
        myHeap.push(inp);
        if (myHeap.size()<=2){
            cout<<-1;
        }
        else{
            long long top1=myHeap.top(); myHeap.pop();
            long long top2=myHeap.top(); myHeap.pop();
            long long top3=myHeap.top(); myHeap.pop();
            cout<<top1*top2*top3;
            myHeap.push(top1);
            myHeap.push(top2);
            myHeap.push(top3);
        }
        cout<<endl;
    }


    return 0;
}