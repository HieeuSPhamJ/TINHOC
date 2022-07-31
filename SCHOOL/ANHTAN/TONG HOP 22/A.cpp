#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define node first
#define weight second
#define int long long
using namespace std;

struct iii{
    int a, b, w;
};

const int maxN = 2 * 1e5 + 10;

vector <ii> adj[maxN];
int father[maxN];
int visited[maxN];

bool cmp(iii a, iii b){
    return a.w < b.w;
}

void resetAll(){
    for (int i = 0; i < maxN; i++){
        visited[i] = -1;
    }
}

int findFather(int child){
    if (child == father[child]){
        return child;
    }
    return father[child] = findFather(father[child]);
}

int calMax(int a, int b){
    resetAll();

    queue <int> myQueue;
    myQueue.push(a);
    while(!myQueue.empty()){
        int tempV = myQueue.front();
        myQueue.pop();
        for (auto newV: adj[tempV]){
            if (visited[newV.node] == -1){
                visited[newV.node] = max(visited[tempV], newV.weight);
                myQueue.push(newV.node);
            }
        }
        
    }

    return visited[b];
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        father[i] = i;
    }
    vector <iii> E;
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        E.push_back({a,b,w});
    }
    sort(E.begin(), E.end(), cmp);

    vector <iii> usedE;
    vector <iii> unusedE;

    for (auto tempE: E){
        int a = findFather(tempE.a);
        int b = findFather(tempE.b);
        if (a == b){
            unusedE.push_back(tempE);
            continue;
        }
        usedE.push_back(tempE);
        adj[tempE.a].push_back({tempE.b, tempE.w});
        adj[tempE.b].push_back({tempE.a, tempE.w});
        father[a] = b;
    }

    // for (auto tempE: usedE){
    //     cout << tempE.a << " " << tempE.b << " " << tempE.w << endl;
    // }

    // cout << endl;

    // for (auto tempE: unusedE){
    //     cout << tempE.a << " " << tempE.b << " " << tempE.w << endl;
    // }

    int ans = 0;

    for (auto tempE: unusedE){
        int val = calMax(tempE.a, tempE.b);
        if (val == tempE.w){
            ans++;
        }
    }

    cout << ans;

    return 0;
}