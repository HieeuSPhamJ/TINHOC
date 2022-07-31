#include<bits/stdc++.h>
#define ii pair <int,int>
#define val first
#define id second
#define len first
#define num second
#define int long long
using namespace std;


const int inf = 1e18;
const int maxN = 2 * 1e5 + 10;

int n, m;

int a[maxN];
int f[maxN];
int k;
vector <ii> adj[maxN];
int visited[maxN];
priority_queue <ii, vector <ii>, greater <ii>> myHeap;

void init(){
    for (int i = 1; i < maxN; i++){
        f[i] = inf;
    }
}

void Dickcha(){
    myHeap.push({0,1});
    f[0] = 0;
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        if (tempV.val > f[])
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    k = a[1];

    Dickcha();

    

    cin >> m;
    for (int i = 1; i <= m; i++){
        int inp;
        cin >> inp;
        int y = inp % k;
        // cout << f[y] << ' ';

        if (f[y] <= inp or inp == 0){
            cout << "TAK";
        }
        else{
            cout << "NIE";
        }
        cout << endl;
    }

    // for (int i = 1; i <= k; i++){
    //     cout << f[i] << endl;
    // }


    return 0;
}