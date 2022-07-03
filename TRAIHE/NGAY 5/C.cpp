#include<bits/stdc++.h>
#define int long long       
#define endl '\n'
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 2 * 1e5 + 10;
const int inf = 1e9 + 10;

int segMin[maxN * 4];
int segMax[maxN * 4];

void updateMin(int i, int left, int right, int index, int val){
    // cout << left << ' ' << right << endl;
    if (index < left or right < index){
        return;
    }
    if (left == right){
        // cout << "#" << endl;
        segMin[i] = val;
        return;
    }

    int mid = (left + right) / 2;

    updateMin(2 * i, left, mid, index, val);
    updateMin(2 * i + 1, mid + 1, right, index, val);

    segMin[i] = min(segMin[2 * i], segMin[2 * i + 1]);
    
}

void updateMax(int i, int left, int right, int index, int val){
    // cout << left << ' ' << right << endl;
    if (index < left or right < index){
        return;
    }
    if (left == right){
        // cout << "#" << endl;
        segMax[i] = val;
        return;
    }

    int mid = (left + right) / 2;

    updateMax(2 * i, left, mid, index, val);
    updateMax(2 * i + 1, mid + 1, right, index, val);

    segMax[i] = max(segMax[2 * i], segMax[2 * i + 1]);
    
}

int getMax(int i, int left, int right, int _left, int _right){
    if (_right < left or right < _left){
        return -inf;
    }
    if (_left <= left and right <= _right){
        return segMax[i];
    }

    int mid = (left + right) / 2;

    return max(getMax(2 * i, left, mid, _left, _right), getMax(2 * i + 1, mid + 1, right, _left, _right));

}

int getMin(int i, int left, int right, int _left, int _right){
    // cout << left << ' ' << right << endl;
    if (_right < left or right < _left){
        // cout << i << '-' << endl;
        return inf;
    }
    if (_left <= left and right <= _right){
        // cout << i << '+' << endl;
        return segMin[i];
    }

    int mid = (left + right) / 2;

    return min(getMin(2 * i, left, mid, _left, _right), getMin(2 * i + 1, mid + 1, right, _left, _right));
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, test;
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        // cout << i << endl;
        int inp;
        cin >> inp;
        updateMax(1, 1, n, i, inp);
        updateMin(1, 1, n, i, inp);
    
    }

    // cout << test;

    // cout << getMax(1, 1, n, 1, n);

    // cout << getMin(1, 1, n, 2, n);

    while(test--){
        int a, b;
        cin >> a >> b;
        cout << getMax(1, 1, n, a, b) - getMin(1, 1, n, a, b) << endl;
    }

    return 0;
}