#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
#define endl '\n'
using namespace std;

struct node{
    vector <int> data;
    node(int len){
        data.resize(4);
    }
};

int countLimit = 0;

int n;
// int a, b, c, d;
int maxFill[5];
int visited[60][60][60][60];
queue <node> myQueue;

void init(){
    for (int i = 0; i < 60; i++){
        for (int j = 0; j < 60; j++){
            for (int e = 0; e < 60; e++){
                for (int k = 0; k < 60; k++){
                    visited[i][j][e][k] = -1;
                }
            }
        }
    }
}

int checkVisited(node Node){
    int a[5];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++){
        a[i] = Node.data[i];
    }
    return visited[a[0]][a[1]][a[2]][a[3]];
}

void setVisited(node Node, int val){
    int a[5];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++){
        a[i] = Node.data[i];
    }
    visited[a[0]][a[1]][a[2]][a[3]] = val;
} 

void printNode(node Node){
    cout << "[";
    for (int i = 0; i < n - 1; i++){
        cout << Node.data[i] << ",";
    }
    cout << Node.data[n - 1] << "]";
    cout << ' ';
}

int getTotal(node Node){
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += Node.data[i];
    }
    return ans;
}

bool checkSame(node A, node B){
    for (int i = 0; i < n; i++){
        if (A.data[i] != B.data[i]){
            return 0;
        }
    }
    return 1;
}

void BFS(node Start, node End){

    setVisited(Start, 0);
    int maxTotal = getTotal(End);
    // cout << maxTotal << endl;
    myQueue.push(Start);

    while(!myQueue.empty()){
        node tempV = myQueue.front();
        myQueue.pop();
        countLimit += n * n + n * n + n;
        // if (checkSame(End, tempV)){
        //     return;
        // }

        // cout  << "-----" << endl;
        // printNode(tempV);
        // cout << endl;
        
        // Type 1
        // cout << "Type 1:" << endl;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i == j){
                    continue;
                }
                node newV = tempV;
                if (newV.data[j] + newV.data[i] <= maxFill[j]){
                    newV.data[j] += newV.data[i];
                    newV.data[i] = 0;
                    if (checkVisited(newV) == -1){
                        myQueue.push(newV);
                        // printNode(newV);
                        setVisited(newV, checkVisited(tempV) + 1);
                    }
                }
            }
        }   
        // cout << endl;
        
        //Type 2
        // cout << "Type 2:" << endl;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i == j){
                    continue;
                }
                node newV = tempV;
                int total = newV.data[j] + newV.data[i];
                if (total >= maxFill[j] and newV.data[i] != 0 and newV.data[j] < maxFill[j]){
                    newV.data[j] = maxFill[j];
                    newV.data[i] = total - maxFill[j];
                    if (checkVisited(newV) == -1){
                        myQueue.push(newV);
                        // printNode(newV);
                        setVisited(newV, checkVisited(tempV) + 1);
                    }
                }
            }
        }
        // cout << endl;

        //Type 3
        // cout << "Type 3:" << endl;
        for (int i = 0; i < n; i++){
            node newV = tempV;
            if (newV.data[i] > 0){
                newV.data[i] = 0;
                // cout << getTotal(newV) << " " << maxTotal << endl;
                if  (getTotal(newV) >= maxTotal and checkVisited(newV) == -1){
                    myQueue.push(newV);
                    // printNode(newV);
                    setVisited(newV, checkVisited(tempV) + 1);
                }
            }
        }
        // cout << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;
    int final[5];
    while(test--){
        init();
        cin >> n;
        node Start(n);
        node End(n);

        for (int i = 0; i < n; i++){
            cin >> maxFill[i];
            Start.data[i] = maxFill[i];
        }
        for (int i = 0; i < n; i++){
            cin >> final[i];
            End.data[i] = final[i];
        }
        BFS(Start, End);
        if (checkVisited(End) == -1){
            cout << "NO";
        }
        else{
            cout << checkVisited(End);
        }
        // cout << "-"<< countLimit;
        cout << endl;
    }
    return 0;
}

/*
3 5 5
0 5 5
3 2 5
0 2 5
2 2 0
0 2 2
0 0 4
*/