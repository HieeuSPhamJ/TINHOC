#include<bits/stdc++.h>

#define int long long
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'

using namespace std;

const int maxN = 3 * 1e5 + 10;
const int inf = 1e18;

int seg[maxN * 4];


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
    seg[i] = (seg[2 * i] + seg[2 * i + 1]);
}

int get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return 0;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return (t1 + t2);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, test;
    cin >> n >> test;
    while(test--){
        int type;
        cin >> type;
        int a, b;
        cin >> a >> b;

        if (type == 1){
            cout << get(1,1,n,a,b) << endl;
        }
        else{
            update(1,1,n,a,b);
        }

    }

    return 0;
}
