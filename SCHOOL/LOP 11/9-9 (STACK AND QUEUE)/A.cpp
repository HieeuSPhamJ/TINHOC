#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // queue <int> myQueue;
    // int n;
    // cin >> n;
    // while(n != 0){
    //     myQueue.push(n);
    //     cin >> n;
    // }
    // myQueue.push(n);
    // while (!myQueue.empty()){
    //     cout << myQueue.front() << " ";
    //     myQueue.pop();
    // }

    int count = 0;

    for (int i = 1; i <= (int)1e8; i++){
        count++;
    }

    cout << count;

    return 0;
}