#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

const int maxN = 3 * 1e5;

int a[maxN];
int visited[maxN];


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
            visited[i] = -1;
        }
         queue <int> myQueue;
        set <int> mySet;
        for (int i = 1; i <= n; i++){
            mySet.insert(i);
        }
        myQueue.push(1);
        visited[1] = 0;
        while(myQueue.empty()){

        }

    }
    return 0;
}
/*

*/