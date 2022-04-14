#include<bits/stdc++.h>
using namespace std;

priority_queue <pair<int, int>> myHeap;
priority_queue <pair<int, int>> clearHeap;

void print(priority_queue <pair<int, int>> tempHeap){
    while (!tempHeap.empty()){
        cout << tempHeap.top().first << '-' << tempHeap.top().second << ' ';
        tempHeap.pop();
    }
    cout << endl;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        // cout << "--#--" << endl;
        // cout << n << ' ' << k << endl;
        for (int i = 1; i <= n; i++){
            int a, b;
            cin >> a >> b;
            // cout << a << ' ' << b << endl;
            myHeap.push(make_pair(b, a));
        }
        // cout << "-----" << endl;
        int ans = 0;
        // print(myHeap);
        for (int i = 1; i <= k; i++){
            int last = -1;
            ans += myHeap.top().first;
            last = myHeap.top().second;
            myHeap.pop();
            vector <pair <int, int>> tempVec;
            // cout << "#" << endl;
            while(!myHeap.empty() and myHeap.top().second == last){
                tempVec.push_back(myHeap.top());
                myHeap.pop();
                // print(myHeap);
            }
            if (myHeap.empty()){
                ans = -1;
                break;
            }
            ans += myHeap.top().first;
            myHeap.pop();
            for (auto i: tempVec){
                myHeap.push(i);
            }
        }
        
        myHeap = clearHeap;
        cout << ans;
        cout << endl;
    }
}