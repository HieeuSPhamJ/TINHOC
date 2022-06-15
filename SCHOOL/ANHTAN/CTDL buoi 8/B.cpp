#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxN = 5e5;

int seg[maxN * 4];

void update(int i, int left, int right, int val, int index){
    // cout << i << ' ' << left << ' ' << right << endl;
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i] = val;
        // cout << "#" << endl;
        return;
    }

    int mid = (left + right) / 2;
    update(2 * i, left, mid, val, index);
    update(2 * i + 1, mid + 1, right, val, index);
    seg[i] = __gcd(seg[2 * i], seg[2 * i + 1]);
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

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        // cout << inp << ' ' << i << endl;
        update(1, 1, n, inp, i);
    }

    int maxAns = 0;

    for (int i = 1; i + k - 1 <= n; i++){
        maxAns = max(maxAns, get(1, 1, n, i, i + k - 1));
    }

    cout << maxAns;


    return 0;
}