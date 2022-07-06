#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define ll long long
using namespace std;

struct node{
    vector <int> data;
    node(int len){
        data.resize(4);
    }
};

int n;
int maxFill[5];
map <node, int> visited;
queue <node> myQueue;

// void BFS(node Start){
//     visited.clear();

//     visited[Start] = 1;
    
//     myQueue.push(Start);

//     while(!myQueue.empty()){
//         node tempV = myQueue.front();
//         myQueue.pop();
        
//         if (visited[tempV] != 0){
//             continue;
//         }
//         //Type 1
//         for (int i = 0; i < n; i++){
//             for (int j = 0; j < n; j++){
//                 if (i == j){
//                     continue;
//                 }
//                 node newV = tempV;
//                 if (newV.data[j] + newV.data[i] <= maxFill[j]){
//                     newV.data[j] += newV.data[i];
//                     newV.data[i] = 0;
//                     myQueue.push(newV);
//                     visited[newV] = visited[tempV] + 1;
//                 }
//             }
//         }
        
//         //Type 2
//         for (int i = 0; i < n; i++){
//             for (int j = 0; j < n; j++){
//                 if (i == j){
//                     continue;
//                 }
//                 node newV = tempV;
//                 int total = newV.data[j] + newV.data[i];
//                 if (total >= maxFill[j] and newV.data[i] != 0){
//                     newV.data[j] = maxFill[j];
//                     newV.data[i] = total - maxFill[j];
//                     myQueue.push(newV);
//                     visited[newV] = visited[tempV] + 1;
//                 }
//             }
//         }
//         for (int i = 0; i < n; i++){
//             node newV = tempV;
//             if (newV.data[i] > 0){
//                 newV.data[i] = 0;
//                 myQueue.push(newV);
//                 visited[newV] = visited[tempV] + 1;
//             }
//         }
//     }

// }

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;
    int a[5];
    while(test--){
        
        cin >> n;
        node Start(n);
        node End(n);
        for (int i = 0; i < n; i++){
            cin >> maxFill[i];
            Start.data[i] = maxFill[i];
        }
        for (int i = 0; i < n; i++){
            cin >> a[i];
            End.data[i] = a[i];
        }
    //     BFS(Start);
        if (visited[End] == 0){
            cout << -1;
        }
        else{
            cout << visited[End] - 1;
        }

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