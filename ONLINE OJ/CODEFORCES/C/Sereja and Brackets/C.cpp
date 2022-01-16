#include<bits/stdc++.h>
using namespace std;

const int maxN = 4 * 1e6 + 10;


struct nodeSeg{
    int ac;
    int close;
    int open;
};
string s;
nodeSeg it[maxN];

nodeSeg com(nodeSeg node1, nodeSeg node2){
    nodeSeg tempNode;
    int minBra = min(node1.open, node2.close);
    tempNode.ac = node1.ac + node2.ac + minBra;
    tempNode.close = node1.close + node2.close - minBra;
    tempNode.open = node1.open + node2.open - minBra;
    return tempNode;
}

void BuildSeg(int index, int left, int right){
    if (left == right){
        it[index].ac = 0;
        if (s[left] == '('){
            it[index].close = 0;
            it[index].open = 1;
        }
        else{
            it[index].close = 1;
            it[index].open = 0;
        }
        return;
    }
    
    int mid = (left + right) / 2;
    BuildSeg(2 * index, left, mid);
    BuildSeg(2 * index + 1, mid + 1, right);
    it[index] = com(it[2 * index], it[2 * index + 1]);


}

nodeSeg Solve(int now, int left, int right, int l, int r){
    if (l == left and r == right){
        return it[now];
    }
    int mid = (left + right) / 2;
    if (r <= mid){
        return Solve(2 * now, left, mid, l, r);
    }
    if (l > mid){
        return Solve(2 * now + 1, mid + 1, right, l, r);
    }
    return com(Solve(2 * now, left, mid, l, mid), Solve(2 * now + 1, mid + 1, right, mid + 1, r));
}


int main(){
    // int n;
    // cin >> n;
    cin >> s;
    s = "0" + s;
    BuildSeg(1, 1, s.length());
    int test;
    cin >> test;
    while(test--){
        int left, right;
        cin >> left >> right;
        cout << 2 * Solve(1, 1, s.length(), left, right).ac;
        cout << endl;
    }

    return 0;
}




