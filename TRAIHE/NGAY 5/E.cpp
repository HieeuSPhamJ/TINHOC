#include<bits/stdc++.h>
// #define int long long
#define ii pair <int,int>
#define f first
#define s second
#define endl "\n"
using namespace std;

const int inf = 1e9;
const int maxN = 3 * 1e5 + 10;

int seg[maxN * 4];
int a[maxN];


void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i] = val;
        return;
    }

    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);

    seg[i] = __gcd(seg[2 * i + 1], seg[2 * i]);
    
}


int get(int i, int left, int right, int _left, int _right){
        if (_right < left or right < _left){
            return 0;
        }
        if (_left <= left and right <= _right){
            return seg[i];
        }

        int mid = (left + right) / 2;

        return __gcd(get(2 * i, left, mid, _left, _right), get(2 * i + 1, mid + 1, right, _left, _right));
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;

    for (int i = 0; i < 4 * maxN; i++){
        seg[i] = inf;
    }

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        update(1, 1, n, i, abs(a[i] - a[i - 1]));
    }

    while(test--){
        int left;
        int right;
        cin >> left >> right;
        cout << get(1, 1, n, left + 1, right) << endl;
    }

    

    return 0;
}