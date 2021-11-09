#include<bits/stdc++.h>
using namespace std;


int main() {
	while(true){
        int n;
        cin>>n;
        if (!n){
            return 0;
        }
        priority_queue <int,vector<int>,greater<int>> myHeap;
        for (int i=1;i<=n;i++){
            int inp;
            cin>>inp;
            myHeap.push(inp);

        }
        // int count=0;
        int cost=0;
        while(myHeap.size()>=2){
            int tempSum=myHeap.top();
            myHeap.pop();
            tempSum+=myHeap.top();
            myHeap.pop();
            cost+=tempSum;
            // myHeap.pop();
            // cout<<tempSum<<' ';
            // cout<<cost<<endl;
            myHeap.push(tempSum);

        }
        cout<<cost<<endl;
        // cout<<count;
    }
	return 0;
}