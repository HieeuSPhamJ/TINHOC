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

int seg[maxN * 4];
int lazy[maxN * 4];

void setLazy(int i){
    int v = lazy[i];
    if (v == inf){
        return;
    }
    lazy[2 * i] = min(lazy[2 * i], v);
    lazy[2 * i + 1] = min(lazy[2 * i + 1], v);
    seg[2 * i] = min(seg[2 * i], v);
    seg[2 * i + 1] = min(seg[2 * i + 1], v);
    lazy[i] = inf;
}

void setLazyForce(int i){
    int val = lazy[i];
    if (val == inf){
        return;
    }
    lazy[2 * i] = val;
    lazy[2 * i + 1] = val;
    seg[2 * i] = val;
    seg[2 * i + 1] = val;
    lazy[i] = inf;
}

void update(int i, int left, int right, int _left, int _right, int val){
    // cout << "!" << left << " " << right << " " << val << endl;
    if (right < _left or _right < left){
        return;
    }
    if (_left <= left and right <= _right){
        seg[i] = min(seg[i],val);
        lazy[i] = min(lazy[i],val);
        // cout << "!" << left << " " << right << " " << seg[i] << endl;
        return;
    }

    setLazy(i);
    int mid = (left + right) / 2;
    
    update(2 * i, left, mid, _left, _right, val);
    update(2 * i + 1, mid + 1, right, _left, _right, val);
    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
}

void updateForces(int i, int left, int right, int _left, int _right, int val){
    if (right < _left or _right < left){
        return;
    }
    if (_left <= left and right <= _right){
        seg[i] = val;
        lazy[i] = val;
        return;
    }
    setLazyForce(i);
    int mid = (left + right) / 2;

    updateForces(2 * i, left, mid, _left, _right, val);
    updateForces(2 * i + 1, mid + 1, right, _left, _right, val);
    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
}

signed main(){
	//freopen("input.INP", "r", stdin);
	//freopen("output.OUT", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	return 0;
}