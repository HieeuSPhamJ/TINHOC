#include<bits/stdc++.h>
using namespace std;

long long a[10004];
long long t[10004];
int n;


bool check(long long time){
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> myArray;
    for (int i=1;i<=n;i++){
        int step=time/t[i];
        int left=a[i]-step;
        if (left<=0){
            left=1;
        }
        int right=a[i]+step;
        if (right>n){
            right=n;
        }
        // cout<<left<<' '<<right<<endl;
        myArray.push(make_pair(left,right));
    }
    priority_queue <int,vector<int>,greater<int>> myHeap;
    for (int i=1;i<=n;i++){
        while (!(myArray.empty())){
            if (myArray.top().first>i){
                break;
            }
            int right=myArray.top().second;
            myArray.pop();
            // cout<<i<<','<<right<<' ';
            myHeap.push(right);
        }
        // cout<<endl;
        if (myHeap.empty()){
            return 0;
        }
        while (myHeap.top()<i){
            myHeap.pop();
            if (myHeap.empty()){
            return 0;
            }
        }
        // cout<<endl;
        myHeap.pop();
    }
    return 1;
}


int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>t[i];
    }
    int left=0;
    int right=1e8;
    while(left<=right){
        long long mid=(left+right)/2;
        // cout<<left<<' '<<right<<' '<<mid<<endl;
        if (check(mid)){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
        // cout<<mid<<endl;
    }
    cout<<left;
    // cout<<check(9);
}

/*
4 5
3 3
2 4
2 2
1 3
*/