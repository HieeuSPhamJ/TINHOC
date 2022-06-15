#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

const int maxN = 3 * 1e5 + 1;

int a[maxN];
int seg[maxN * 4];
map <int, vector<int>> listMap;

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
    int n;
    cin >> n;
    int test;
    cin >> test;

    for (int)

    while(test--){
        

    }

    return 0;
}