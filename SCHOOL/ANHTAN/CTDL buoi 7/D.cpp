#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
#define endl "\n"
using namespace std;

const int maxN = 1e5 + 10;
const int inf = 1e18;

int n;
int seg[maxN * 4];
int lazy[maxN * 4];

void lazz(int i){
    int val = lazy[i];

    seg[2 * i] += val;
    seg[2 * i + 1] += val;
    lazy[2 * i] += val;
    lazy[2 * i + 1] += val;

    lazy[i] = 0;
}

void printTree(){
    // cout << n << endl;
    int count = 0;
    int por = 1;
    for (int i = 1; i <= 4 * n; i++){
        cout << "[" << seg[i] << ", " << lazy[i] << "] ";
        count++;
        if (count == por){
            por *= 2;
            count = 0;
            cout << endl;
        }
    }
    cout << endl;
}


void update(int i, int left, int right, int _left, int _right, int val){
    if (_right < left or right < _left){
        return;
    }
    if (_left <= left and right <= _right){
        lazy[i] += val;
        seg[i] += val;
        return;
    }

    lazz(i);
    
    int mid = (left + right) / 2;

    update(2 * i, left, mid, _left, _right, val);
    update(2 * i + 1, mid + 1, right, _left, _right, val);

    seg[i] = max(seg[2 * i + 1], seg[2 * i]);
    
}


int get(int i, int left, int right, int _left, int _right){
        if (_right < left or right < _left){
            return -inf;
        }
        if (_left <= left and right <= _right){
            return seg[i];
        }

        lazz(i);

        int mid = (left + right) / 2;

        return max(get(2 * i, left, mid, _left, _right), get(2 * i + 1, mid + 1, right, _left, _right));
}

main(){
    cin >> n;
    int test;
    cin >> test;
    while (test--){
        int q;
        cin >> q;
        if (q == 0){
            int a, b, val;
            cin >> a >> b >> val;
            update(1, 1, n, a, b, val);
        }
        else{
            int a, b;
            cin >> a >> b;
            cout << get(1, 1, n, a, b) << endl;
        }
    }

    // printTree();
    

    return 0;
}

/*
1 2 3 2 1 2 3 4 3 2 1 5 4 1 2 3 2 2 1 


*/