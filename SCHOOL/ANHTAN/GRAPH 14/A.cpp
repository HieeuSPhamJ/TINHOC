#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define ll long long
using namespace std;

const int maxN = 2 * 1e5 + 10;

struct iii{
    int val, index, father, chanle;
};

int visited[3][maxN];
int extraDis[maxN];
int trans[maxN];

queue <iii> myQueue;
int ans[maxN];
int a[maxN];

vector <int> adj[maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        ans[i] = -1;
        myQueue.push({a[i], i, i, (a[i] % 2)});
    }

    

    for (int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }




    return 0;
}
