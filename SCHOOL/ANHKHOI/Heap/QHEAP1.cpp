#include<bits/stdc++.h>
using namespace std;

priority_queue <int,vector<int>,greater<int>> myHeap;

void check(){
    priority_queue<int,vector<int>,greater<int>>checkHeap=myHeap;
    while(!checkHeap.empty()){
        cout<<checkHeap.top()<<' ';
        checkHeap.pop();
    }
    cout<<endl;

}


int main() {
    int question;
    cin>>question;
	while(question--){
        int test;
        cin>>test;
        if (test==1){
            int inp;
            cin>>inp;
            myHeap.push(inp);
        }
        else if (test==2){
            int inp;
            cin>>inp;
            queue <int> tempQueue;
            while(myHeap.top()!=inp){
                tempQueue.push(myHeap.top());
                myHeap.pop();
            }
            myHeap.pop();
            while(!tempQueue.empty()){
                myHeap.push(tempQueue.front());
                tempQueue.pop();
            }

        }
        else{
            cout<<myHeap.top();
            cout<<endl;
        }
        // check();
        // cout<<test;
    }
	return 0;
}