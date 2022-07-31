#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 1000;
const int maxNN = maxN * maxN;

int n, s;
int a[maxN + 10][maxN + 10];
ii b[maxNN + 10];
int grid[maxNN + 10];
int Start = 0;
int End = 0;
set <int> adj[maxNN + 10];
vector <int> listHive;
int timeBee[maxNN + 10];
int visited[maxNN + 10];
queue <int> myQueue;

vector <ii> dir = {
    {0,1},
    {1,0},
    {-1,0},
    {0,-1}
};

bool checkInside(int x, int y){
    if (x >= 1 and x <= n and y >= 1 and y <= n){
        return 1;
    }
    return 0;
}

void getBeeTime(){
    for (int i = 0; i < maxNN; i++){
        timeBee[i] = -1;
    }
    for (auto i: listHive){
        myQueue.push(i);
        timeBee[i] = 0;
    }

    while(!myQueue.empty()){
        int tempV = myQueue.front();
        myQueue.pop();
        // cout << tempV << ": ";
        for (auto newV: adj[tempV]){
            if (timeBee[newV] == -1 and grid[newV] == 0){
                timeBee[newV] = timeBee[tempV] + 1;
                myQueue.push(newV);
                // cout << newV << ' ';
            }
        }
        // cout << endl;
    }

    // for (int i = 0; i <= 50; i++){
    //     cout << timeBee[i] << ' ';
    // }

}

int check(int beginTime){
    for (int i = 0; i < maxNN; i++){
        visited[i] = -1;
    }
    myQueue.push(Start);
    visited[Start] = beginTime * s;

    if (timeBee[Start] <= beginTime){
        return 0;
    }

    while(!myQueue.empty()){
        int tempV = myQueue.front();
        myQueue.pop();
        // cout << tempV << ": ";
        for (auto newV: adj[tempV]){
            if (visited[newV] == -1 and grid[newV] == 0 and timeBee[newV] > ((visited[tempV] + 1) / s)){
                visited[newV] = visited[tempV] + 1;
                myQueue.push(newV);
                // cout << newV << "," << timeBee[newV] << "," << visited[newV] << "  ";
            }
        }
        // cout << endl;
    }

    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= n; j++){
    //         cout << visited[a[i][j]] / s << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= n; j++){
    //         cout << timeBee[a[i][j]] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    if (visited[End] == -1){
        return 0;
    }
    return visited[End];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> s;
    
    int countCell = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            countCell++;
            char inp;
            cin >> inp;
            a[i][j] = countCell;
            b[countCell] = {i,j};
            if (inp == 'T'){
                grid[countCell] = 1;
            }
            else if (inp == 'H'){
                grid[countCell] = 1;
                listHive.push_back(countCell);
            }
            else if (inp == 'M'){
                Start = countCell;
            }
            else if (inp == 'D'){
                End = countCell;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int t = a[i][j];
            for (auto d: dir){
                int x = i + d.fi;
                int y = j + d.se;
                int n = a[x][y];
                if (checkInside(x, y)){
                    adj[t].insert(n);
                    adj[n].insert(t);            
                }
            }
        }
    }

    getBeeTime();

    int left = 0;
    int right = 1e8;
    int ans = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        if (check(mid)){
            ans = max(ans, mid);
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    
    // ans = check(2);

    cout << ans;

    return 0;
}