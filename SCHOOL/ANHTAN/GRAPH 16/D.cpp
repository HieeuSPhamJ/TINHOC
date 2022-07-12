#include<bits/stdc++.h>
#define ii pair <int,int>  
#define x first
#define y second
#define val first
#define id second
#define len first
#define num second
#define int long long
using namespace std;

const int inf = 1e18;
const int maxN = 1010;
const int maxNN = maxN * maxN;

int Start, End;
int a[maxN][maxN];
int b[maxN][maxN];
int c[maxNN];
int boss[maxNN];
int sizeCom[maxNN];
set <ii> adj[maxNN];
int visited[maxNN];
priority_queue <ii, vector <ii>, greater <ii>> myHeap;

ii dir[] = {
    {0, -1},
    {0, 1},
    {-1, 0},
    {1, 0}
};

void init(){
    for (int i = 1; i < maxNN; i++){
        visited[i] = inf;
    }
}

void Dickcha(){
    myHeap.push({0, Start});
    visited[Start] = 0;
    while(!myHeap.empty()){
        ii tempV = myHeap.top();
        myHeap.pop(); 
        // cout << "#" << tempV.id << endl;
        if (tempV.len != visited[tempV.id]){
            continue;
        }
        for (auto newV: adj[tempV.id]){
            if (visited[tempV.id] + newV.val < visited[newV.id]){
                // cout << newV.id << ' ';
                visited[newV.id] = visited[tempV.id] + newV.val;
                myHeap.push({visited[newV.id], newV.id});
            }
        }
        // cout << endl;
    }
}

int findBoss(int node){
    if (node == boss[node]){
        return node;
    }
    return boss[node] = findBoss(boss[node]);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int count = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            b[i][j] = count;
            boss[count] = count;
            c[count] = a[i][j];
            sizeCom[count] = 1;
            count++;
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int d = 0; d < 4; d++){
                int newX = i + dir[d].x;
                int newY = j + dir[d].y;
                
                if (a[i][j] == a[newX][newY]){
                    int u = findBoss(b[i][j]);
                    int v = findBoss(b[newX][newY]);
                    if (u == v){
                        continue;
                    }
                    boss[u] = v;
                    sizeCom[v] += sizeCom[u];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            b[i][j] = findBoss(b[i][j]);
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            // cout << b[i][j] << ' ';
            for (int d = 0; d < 4; d++){
                int newX = i + dir[d].x;
                int newY = j + dir[d].y;
                int A = b[i][j];
                int B = b[newX][newY];
                if (A != B and A != 0 and B != 0){
                    adj[A].insert({sizeCom[B] * c[B] * !(c[B] == 1), B});
                    adj[B].insert({sizeCom[A] * c[A] * !(c[A] == 1), A});
                }
            }
        }
        // cout << endl;
    }
    // cout << endl;

    // for (int i = 1; i <= count; i++){
    //     // cout << i << ": " << sizeCom[i] << "," << c[i] << endl;
    //     if (adj[i].size() != 0){
    //         cout << i << ": ";
    //         for (auto tempV: adj[i]){
    //             cout << tempV.id << "," << tempV.val << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    Start = b[1][1];
    End = b[n][m];

    init();
    Dickcha();

    int cost11 = sizeCom[b[1][1]] * c[b[1][1]] * !(c[b[1][1]] == 1);
    int costnm = sizeCom[b[n][m]] * c[b[n][m]] * !(c[b[n][m]] == 1);
    cout << visited[End] + cost11;


    return 0;
}