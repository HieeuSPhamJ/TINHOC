#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 3 * 1e5 + 10;

int seg[maxN * 4];

void update(int index, int left, int right, int id, int value){
    // cout << id << " " << left << " " << right << endl;
    if (id < left or right < id){
        return;
    }
    if (left == right){
        seg[index] = value;
        return;
    }
    int mid = (left + right) / 2;
    update(index * 2, left, mid, id, value);
    update(index * 2 + 1, mid + 1, right, id, value);
    seg[index] = (seg[index * 2] + seg[index * 2 + 1]);
}

int get(int index, int left, int right, int _left, int _right){
    if (_right < left or right < _left){
        return 0;
    }
    if (_left <= left and right <= _right){
        return seg[index];
    }

    int mid = (left + right) / 2;

    int t1 = get(index * 2, left, mid, _left, _right);
    int t2 = get(index * 2 + 1, mid + 1, right, _left, _right);

    return t1 + t2;
}   

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        update(1,1,n,i,1);    
    }
    
    int cap = n;

    while(test--){
        int i;
        cin >> i;
        if (i > cap or cap == 0){
            cout << 0 << endl;
            continue;
        }
        int left = 1;
        int right = n;
        int ans = 0;
        while(left <= right){
            int mid = (left + right) / 2;
            int pre = get(1,1,n,1,mid - 1);
            if (pre < i){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        update(1,1,n,ans,0);
        cap--;
        cout << ans << endl;
    }
    return 0;
}