#include<bits/stdc++.h>
using namespace std;

vector <int> countVect;
vector <int> adj;
int maze[2001][2001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("CHUYEN03.INP", "r", stdin);
    freopen("CHUYEN03.OUT", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        maze[a][b] = 1;
    }
    int count = 0;
    for (int i = 1; i <= n; i++){
        countVect.push_back(count);
        for (int j = 1; j <= n; j++){
            int inp = maze[i][j];
            if (inp){
                count++;
                adj.push_back(j);
            }
        }
    }
    countVect.push_back(count);
    for (auto i: countVect){
        cout << i << ' ';
    }
    cout << endl;
    for (auto i: adj){
        cout << i << ' ';
    }
    return 0;
}