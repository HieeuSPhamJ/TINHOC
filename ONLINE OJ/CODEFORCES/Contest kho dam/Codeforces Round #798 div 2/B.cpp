#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define ll long long
using namespace std;

const int maxN = 1e3 + 10;
int a[maxN];
priority_queue <int, vector <int>, greater <int>> myHeap;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            myHeap.push(a[i]);
        }

        for (int i = 1; i <= n; i++){
            if (a[i] == myHeap.top()){        
                myHeap.pop();
                cout << myHeap.top() << ' ';
                myHeap.pop();
                myHeap.push(a[i]);
            }
            else{
                cout << myHeap.top() << ' ';
                myHeap.pop();
            }
        }
        cout << endl;
    }
    return 0;
}