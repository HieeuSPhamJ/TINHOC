#include<bits/stdc++.h>
using namespace std;

int point[210];
vector <int> adj[210];

bool check[210] = {false};

void DFS(int n){
    check[n] = 1;
    // cout << n << ":" << point[n] << ' ';
    for (int i = 0; i < adj[n].size(); i++){
        if (check[adj[n][i]] == 0){
            DFS(adj[n][i]);
        }
    }
}


int main(){
    freopen("SPC3.INP", "r", stdin);
    freopen("SPC3.OUT", "w", stdout);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> point[i];
            adj[i].clear();
        }
        for (int i = 1; i <= n; i++){
            int maxV;
            cin >> maxV;
            while (maxV--){
                int inp;
                cin >> inp;
                adj[i].push_back(inp);
        
            }
        }
        // for (int i = 1; i <= n; i++){
        //     for (int e = 0; e < adj[i].size(); e++){
        //         cout << adj[i][e] << ' ';
        //     }
        //     cout << "|" << endl;
        // }
        // cout << "----" << endl;
        for (int i = 1; i <= n; i++){
            memset(check, 0, sizeof(check));
            DFS(i);
            // cout << endl;
            int count = 0;
            // cout << i << "#" << endl;

            set <int> checkMap;
            for (int i = 1; i <= 205; i++){
                if (check[i] == 1){
                    checkMap.insert(point[i]);
                }

            }
            // cout << endl;
            cout << checkMap.size() << ' ';
            // cout << endl;
        }
        cout << endl;
    }

    return 0;
}

/*
1:3 2:10 4:3 5:3 6:2 3:2 
2:10 4:3 5:3 6:2 
3:2 
4:3 
5:3 6:2 
6:2
*/
