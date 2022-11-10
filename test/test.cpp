#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'

using namespace std;

const int maxN = 2 * 1e5 + 10;
const int inf = 1e18;

int N = maxN;
int seg[maxN * 4];
multiset <int> store;

void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i] += val;
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

int sizeTrain(){
    return seg[1];
}

int getGreater(int val){
    return get(1,1,N,val + 1, N);
}

void insertVal(int val){
    update(1,1,N,val,1);
    store.insert(val);
}

int getLast(){
    auto it = store.end();
    it--;
    return *it;
}

void removeVal(int val){
    update(1,1,N,val,-1);
    store.erase(store.find(val));
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    insertVal(1);
    insertVal(2);
    insertVal(2);
    insertVal(3);
    insertVal(3);
    insertVal(4);
    insertVal(5);
    
    cout << getGreater(2) << endl;
    removeVal(5);
    cout << getGreater(2) << endl;
    cout << sizeTrain();
    return 0;
}