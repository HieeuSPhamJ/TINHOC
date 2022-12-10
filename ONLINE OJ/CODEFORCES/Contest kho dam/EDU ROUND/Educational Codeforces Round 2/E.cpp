#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 1e5 + 10;

int color[maxN];
int ans[maxN];
int bigChild[maxN];
int countColor[maxN];
int sizeTree[maxN];
int maxColor[maxN];
int sumMax[maxN];
vector <int> adj[maxN];
vector <int> listChild[maxN];

void findBigChild(int node, int father){
    sizeTree[node] = 1;
    int maxSize = 0;
    for (auto newNode: adj[node]){
        if (newNode != father){
            findBigChild(newNode, node);
            sizeTree[node] += sizeTree[newNode];
            if (maxSize < sizeTree[newNode]){
                maxSize = sizeTree[newNode];
                bigChild[node] = newNode;
            }
        }
    }
}

void DFS(int node, int father, int keep){
    for (auto newNode: adj[node]){
        if (father == newNode or newNode == bigChild[node]){
            continue;
        }
        DFS(newNode, node, 0);
    }

    if (bigChild[node] != 0){
        DFS(bigChild[node], node, 1);
        swap(listChild[node], listChild[bigChild[node]]); 
        maxColor[node] = maxColor[bigChild[node]];
        sumMax[node] = sumMax[bigChild[node]];
    }

    listChild[node].push_back(node);
    countColor[color[node]]++;

    if (countColor[color[node]] > maxColor[node]){
        maxColor[node] = countColor[color[node]];
        sumMax[node] = 0;
    }
    if (countColor[color[node]] == maxColor[node]){
        sumMax[node] += color[node];
    }

    for (auto child: adj[node]){
        if (father == child or child == bigChild[node]){
            continue;
        }
        for (auto childOfChild: listChild[child]){
            countColor[color[childOfChild]]++;
            listChild[node].push_back(childOfChild);
            if (countColor[color[childOfChild]] > maxColor[node]){
                sumMax[node] = 0;
                maxColor[node] = countColor[color[childOfChild]];
            }
            if (countColor[color[childOfChild]] == maxColor[node]){
                sumMax[node] += color[childOfChild];
            }
        }
        //em thiếu cộng ở đây:)))
        
    }

    ans[node] = sumMax[node];

    if (keep == 0){
        for (auto child: listChild[node]){
            countColor[color[child]]--;
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> color[i];
    }
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        // cout << a << " " << b << endl;
    }
    findBigChild(1,1);
    DFS(1,1, 0);

    for (int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
        // cout << bigChild[i] << ' ';
    }
    return 0;
}