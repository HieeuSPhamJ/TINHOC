#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int seg[maxN * 4];
int lazy[maxN * 4];

void setLazy(int i){
    int value = lazy[i];
    lazy[i * 2] += value;
    lazy[i * 2 + 1] += value; 
    seg[i * 2] += value;
    seg[i * 2 + 1] += value; 
    lazy[i] = 0;
}

void update(int index, int left, int right, int _left, int _right, int value){
    // cout << id << " " << left << " " << right << endl;
    if (_right < left or right < _left){
        return;
    }
    if (_left <= left and right <= _right){
        lazy[index] += value;
        seg[index] += value;
        return;
    }
    setLazy(index);
    int mid = (left + right) / 2;
    update(index * 2, left, mid, _left, _right, value);
    update(index * 2 + 1,mid + 1, right, _left, _right, value);
    seg[index] = max(seg[index * 2], seg[index * 2 + 1]);
}

int get(int index, int left, int right, int _left, int _right){
    if (_right < left or right < _left){
        return -1e18;
    }
    if (_left <= left and right <= _right){
        return seg[index];
    }

    setLazy(index);
    int mid = (left + right) / 2;

    int t1 = get(index * 2, left, mid, _left, _right);
    int t2 = get(index * 2 + 1, mid + 1, right, _left, _right);

    return max(t1,t2);
}   

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    while(test--){
        int type;
        int a, b;
        cin >> type >> a >> b;
        if (type == 1){
            cout << get(1,1,n,a,b) << endl;
        }
        else{
            int x;
            cin >> x;
            update(1,1,n,a,b,x);
        }
    }
    return 0;
}