#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 4 * 1e5 + 10;

int n;
int m;
int a[maxN];

priority_queue<int> myMaxHeap;
priority_queue<int, vector <int>, greater<int>> myMinHeap;

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    m = 3 * n;

    int sumAll = 0;

    for (int i = 1; i <= m; i++){
        cin >> a[i];
        sumAll += a[i];
    }

    for (int i = 1; i <= n * 2; i++){
        myMaxHeap.push(a[i]);
    }

    int sumMax = 0;

    for (int i = 1; i <= n; i++){
        sumMax += myMaxHeap.top();
        // cout << myMaxHeap.top() << endl;
        myMaxHeap.pop();
    }

    for (int i = 0; i < 2 * n; i++){
        myMinHeap.push(a[m - i]);
    }

    int sumMin = 0;

    for (int i = 1; i <= n; i++){
        sumMin += myMinHeap.top();
        myMinHeap.pop();
    }


    cout << sumMax - sumMin;


    return 0;
}


