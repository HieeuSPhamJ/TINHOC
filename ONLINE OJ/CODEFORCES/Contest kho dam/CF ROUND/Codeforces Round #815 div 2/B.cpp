#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int Ma = 0;
        int Mi = 1e18;
        priority_queue <int> maxHeap;
        priority_queue <int, vector <int>, greater <int>> minHeap;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            maxHeap.push(a[i]);
            minHeap.push(a[i]);
        }
        int x1 = maxHeap.top();
        maxHeap.pop();
        int x2 = maxHeap.top();

        int y1 = minHeap.top();
        minHeap.pop();
        int y2 = minHeap.top();

        cout << x1 - y1 + x2 - y2 << endl;
    }
    return 0;
}