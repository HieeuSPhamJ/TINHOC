#include <bits/stdc++.h>
using namespace std;


int root[10000];


int findRoot(int n){
    if (n == root[n]){
        return n;
    }
    return root[n] = findRoot(root[n]);
}


int main(){
    for (int i = 1; i <= 10000 - 1; i++){
        root[i] = i;
    }
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        if (findRoot(a) == findRoot(b)){
            continue;
        }
        else{
            root[findRoot(a)] = findRoot(b);
        }
    }
    while(t--){
        int a, b;
        cin >> a >> b;
        if (findRoot(a) == findRoot(b)){
                cout << "YES";
            }
            else cout << "NO";
        cout << endl;
    }
}