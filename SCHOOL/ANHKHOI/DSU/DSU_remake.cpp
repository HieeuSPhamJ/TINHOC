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
    while(true){
        int q;
        int a, b;
        cin >> q;
        cin >> a >> b;
        if (q == 1){
            if (findRoot(a) == findRoot(b)){
                cout << "Valid";
            }
            else cout << "Invalid";
        }
        else{
            if (findRoot(a) == findRoot(b)){
                continue;
            }
            else{
                root[a] = b;
            }
        }
        cout << endl;
    }
}