#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;
    
const int maxN = 1e3 + 10;

int n, m, k;
int prefix[maxN][maxN];
int a[maxN][maxN];
int visited[maxN][maxN];
vector <ii> dir = {
    {1,0},
    {0,1},
    {-1,0},
    {0,-1}
};


void genMaze(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            visited[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; i++){
        int temp = 0;
        for (int j = 1; j <= m; j++){
            temp += prefix[i][j];
            a[i][j] = temp;
        }
    }

}

bool checkIn(int i, int j, int x, int y, int r){
    if (pow(i - x, 2) + pow(j - y, 2) <= r * r){
        return 1;
    }
    return 0;
}

void mark(int x, int y, int r){
    // cout << "MARK: " << x << " " << y << " " << r << endl;

    int up = x - r;
    int down = x + r;

    if (up < 1){
        up = 1;
    }

    if (down > n){
        down = n;
    }

    for (int i = up; i <= down; i++){
        int left = y - r;
        int right = y;
        int j = 0;
        while(left <= right){
            int mid = (left + right) / 2;
            if (checkIn(i, mid, x, y, r) == 1){
                right = mid - 1;
                j = mid;
            }
            else{
                left = mid + 1;
            }
        }
        // cout << i << "-" << j << " " << i << "-" << y + abs(y - j) << endl;
        prefix[i][max(j, 1ll)] += 1;
        prefix[i][min(m + 1, y + abs(y - j)) + 1] -= 1;

    }
}

void print(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}


void BFS(){
    queue <ii> myQueue;
    visited[1][1] = 0;
    myQueue.push({1,1});

    while(!myQueue.empty()){
        ii tempV = myQueue.front();
        // cout << tempV.fi << "-" << tempV.se << endl;
        myQueue.pop();
        for (auto i: dir){
            ii newV = {tempV.fi + i.fi, tempV.se + i.se}; 
            if (visited[newV.fi][newV.se] == -1 and a[newV.fi][newV.se] == 0 and newV.fi >= 1 and newV.fi <= n and newV.se >= 1 and newV.se <= m){
                visited[newV.fi][newV.se] = visited[tempV.fi][tempV.se] + 1;
                myQueue.push(newV);
                // cout << newV.fi << " " << newV.se << endl;
            }
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;


    for (int i = 1; i <= k; i++){
        int x, y, r;
        cin >> x >> y >> r;
        mark(x,y,r);
    }

    genMaze();

    BFS();

    // print();

    cout << visited[n][m];

    return 0;   
}