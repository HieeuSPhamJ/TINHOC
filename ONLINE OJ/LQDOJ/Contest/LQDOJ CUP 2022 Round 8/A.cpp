#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define turn first
#define po se.fi.fi
#define way se.fi.se
#define id se.se
#define iiii pair <int,pair<ii,int>>
#define endl '\n'
using namespace std;

struct node{
    int x, y, type;
};


const int maxN = 1e5 + 10;
const int inf = 1e18;

int N,M, n,m;
int ans = inf;
unordered_map <int, vector <int>> adjX;
unordered_map <int, vector <int>> adjY;
node a[maxN];
int visited[3][maxN][32];

int getx(){
    int left = 0;
    int right = 
}

void dickcha(){
    priority_queue <iiii, vector <iiii>, greater <iiii>> q;
    for (int i = 1; i < maxN; i++){
        for (int j = 0; j <= 1; j++){
            for (int k = 0; k <= 30; k++){
                visited[j][i][k] = inf;
            }
        }
    }
    // q.push({0,{{0,0},0}});

    while(!q.empty()){
        iiii t = q.top();
        q.pop();
        int x = a[t.id].x;
        int y = a[t.id].y;
        int ix = getx(y);
        int iy = gety(x,y);


    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> n >> m;
    for (int i = 1; i <= n; i++){
        node x;
        cin >> x.x >> x.y;
        x.type = 1;
        a[i] = x;
        adjX[x.x].push_back(i);
        adjY[x.y].push_back(i);
    }
    
    for (int i = 1; i <= m; i++){
        node x;
        cin >> x.x >> x.y;
        x.type = -1;
        a[i + n] = x;
        adjX[x.x].push_back(i + n);
        adjY[x.y].push_back(i + n);
    }
    a[0] = {0,0,0};
    dickcha();

    cout << ans << endl;

    return 0;
}