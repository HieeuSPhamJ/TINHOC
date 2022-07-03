#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int inf = 1e9;
const int maxN = 1e6 + 10;

int n;
int a[maxN];
ii b[maxN];
map <int,int> seg;

bool cmp(ii x, ii y){
    return x.s < y.s;
}

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

    seg[i] = seg[2 * i + 1] + seg[2 * i];
    
}


int get(int i, int left, int right, int _left, int _right){
        if (_right < left or right < _left){
            return 0;
        }
        if (_left <= left and right <= _right){
            return seg[i];
        }

        int mid = (left + right) / 2;

        return get(2 * i, left, mid, _left, _right) + get(2 * i + 1, mid + 1, right, _left, _right);
}


int main(){
    cin >> n;

    int maxA = 0;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = {a[i], i};
        maxA = max(maxA, a[i]);
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
        // cout << a[i] << ' ';
    }
    // cout << endl;
    
    long long ans = 0;

    for (int i = 1; i <= n; i++){
        ans += get(1, 1, maxA, a[i] + 1, maxA);
        update(1, 1, maxA, a[i], 1);
    }

    cout << ans;
    

    return 0;
}