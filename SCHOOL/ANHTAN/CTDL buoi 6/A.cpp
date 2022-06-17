#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;


const int maxN = 1e5 + 10;
const int inf = 1e18;

int n, m;
int node[maxN * 4];

void update(int i, int left, int right, int index, int val){
    // cout << i << ' ' << left << ' ' << right << ' ' << index << ' ' << val << endl;
    if (right < index or left > index){
        return;
    }
    if (right == left){
        node[i] += val;
        return;
    }
    int mid = (left + right) / 2;
    update(i * 2, left, mid, index, val);
    update(i * 2 + 1, mid + 1, right, index, val); 

    node[i] = max(node[2 * i], node[2 * i + 1]);
}


int getMax(int i, int left, int right, int Tleft, int Tright){
    cout << i << ' ' << left << ' ' << right << " | " << Tleft << ' ' << Tright << endl;
    if (left > Tright or right < Tleft){
        return -inf;
    }
    if (left >= Tleft and Tright >= right){
        return node[i];
    }

    int mid = (left + right) / 2;

    return max(getMax(2 * i, left, mid, Tleft, Tright), getMax(2 * i + 1, mid + 1, right, Tleft, Tright));
}

main(){
    cin >> n >> m;
    while(m--){
        int test;
        cin >> test;
        if (test == 0){
            int index, val;
            cin >> index >> val;
            update(1, 1, n, index, val);
        }   
        else{
            int left, right;
            cin >> left >> right;
            cout << getMax(1, 1, n, left, right) << endl;
        }
    }

    return 0;
}