#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int inf = 1e18;
const int maxN = 1e5 + 10;

struct node{
    int minNum;
    int num;
};

int n;
int a[maxN];
ii b[maxN];
node seg[maxN * 4];
int dp[maxN];

void printTree(){
    // cout << n << endl;
    int count = 0;
    int por = 1;
    for (int i = 1; i <= 4 * n; i++){
        cout << "[" << seg[i].minNum << ", " << seg[i].num << "] ";
        count++;
        if (count == por){
            por *= 2;
            count = 0;
            cout << endl;
        }
    }
    cout << endl;
}

bool cmp(ii x, ii y){
    return x.s < y.s;
}

node connectNode(node a, node b){
    int minNum = min(a.minNum, b.minNum);
    int num = a.num + b.num;
    return {minNum, num};
}


void update(int i, int left, int right, int index, int val){
    // cout << i << ' ' << left << ' ' << right << endl;
    if (index < left or right < index){
        return;
    }
    if (left == right){
        // cout << "#" << endl;
        seg[i] = {val, 1};
        return;
    }

    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);

    seg[i] = connectNode(seg[2 * i], seg[2 * i + 1]);
        
    
}

node get(int i, int left, int right, int _left, int _right, int k){
    // cout << i << ' ' << left << ' ' << right << " [" << seg[i].minNum << ", " << seg[i].num << "] " << endl;
    if (_right < left or right < _left or seg[i].num == 0){
        return {0, 0};
    }
    if (_left <= left and right <= _right and seg[i].minNum > k){
        // cout << "#" << endl;
        return seg[i];
        
    }

    int mid = (left + right) / 2;
    return connectNode(get(2 * i, left, mid, _left, _right, k), get(2 * i + 1, mid + 1, right, _left, _right, k));

}

main(){
    cin >> n;
    b[0] = {0, 0};
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = {a[i], i};
        dp[i] = 1;
        // update(1, 1, n, i, 1);
    }

    sort(b + 1, b + 1 + n);
    for (int i = 1, j = 0; i <= n; i++){
        if (b[i].f != b[i - 1].f){
            j++;
        }
        b[i].f = j;
        
    }

    sort(b + 1, b + 1 + n, cmp);

    for (int i = 1; i <= n; i++){
        a[i] = b[i].f;
        // cout << i << ' ' << a[i] << endl;
        update(1, 1, n, i, a[i]);

        // cout << a[i] << ' ';
    }
    // cout << endl;

    printTree();
    
    // cout << get(1, 1, n, 2, 4, 2).num << endl;
    
    int test;
    cin >> test;
    while(test--){
        int a, b, k;
        cin >> a >> b >> k;
        cout << get(1, 1, n, a, b, k).num << endl;

    }

    return 0;
}