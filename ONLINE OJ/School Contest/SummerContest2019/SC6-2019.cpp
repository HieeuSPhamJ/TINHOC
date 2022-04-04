#include<bits/stdc++.h>
using namespace std;

const int maxN = 2010;
const int maxM = 5010;

struct nodeData{
    int l;
    int r;
};

int n, m, s, e, k;
nodeData node[maxN];
vector <nodeData> S;
vector <int> adj[maxN];
vector <int> temp;
int visited[maxN];
vector <int> tempTemp;

void Split(){
    tempTemp.clear();
    sort(temp.begin(), temp.end());
    tempTemp.push_back(temp[0]);
    for (int i = 1; i < temp.size(); i++){
        if (tempTemp.back() != temp[i]){
            tempTemp.push_back(temp[i]);
        }
        // cout << temp[i] <<  ' ';
    }
    for (int i = 0; i < tempTemp.size() - 1; i++){
        nodeData tempNode;
        tempNode.l = tempTemp[i] + 1;
        tempNode.r = tempTemp[i + 1];
        S.push_back(tempNode);
        // cout << tempTemp[i] <<  ' ';
    }
    // cout << endl;
    
}

void DFS(int Start, int key){
    visited[Start] = 1;
    // cout << Start << endl << "-";
    // for (int i = 0; i < adj[Start].size(); i++){
    //     int V = adj[Start][i];
    //     if (visited[Start] == 0 and key >= node[V].l and key <= node[V].r){
    //         // DFS(V, key);
    //         cout << '!';
    //     }
    //     cout << V <<' ';
    // }
    // cout << endl;
    for (int i = 0; i < adj[Start].size(); i++){
        int V = adj[Start][i];
        if (visited[Start] == 0 and key >= node[V].l and key <= node[V].r){
            DFS(V, key);
        }
    }
}


int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> n >> m >> s >> e >> k;
        for (int i = 1; i <= n; i++){
            cin >> node[i].l >> node[i].r;
            temp.push_back(node[i].l - 1);
            temp.push_back(node[i].r);
        }
        for (int i = 1; i <= m; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }

        // Split();
        // int countAns = 0;
        // for (int i = 0; i < S.size(); i++){
        //     memset(visited, 0, sizeof(visited));
        //     DFS(s, S[i].l);
        //     if (visited[e] != 0){
        //         countAns += (S[i].r - S[i].l + 1);
        //         cout << '#' << S[i].l << endl;
        //     }
        //     // cout << S[i].l << ' ' << S[i].r << endl;
        // }
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= n; i++){
            for (auto e: adj[i]){
                cout << e << ' ';
            }
            cout << endl;
        }
        DFS(1,3);
        cout << visited[3];
        // cout << countAns;
        // cout << endl;
    }

    return 0;
}

/*

*/