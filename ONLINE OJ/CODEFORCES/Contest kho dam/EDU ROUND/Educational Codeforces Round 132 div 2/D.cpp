#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 2 * 1e5 + 10;
const int inf = 1e18;
int seg[maxN * 4];

int a[maxN];
int grid[maxN];


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

    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
    
}

int get(int i, int left, int right, int _left, int _right){
    if (_right < left or right < _left){
        return inf;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;
    
    return min(get(2 * i, left, mid, _left, _right), get(2 * i + 1, mid + 1, right, _left, _right));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
        grid[i] = n - a[i];
        // cout << grid[i] << ' ';
        update(1,1,m,i,grid[i]);
    }

    // for(int i = 1; i <= m; i++){
    //     cout << grid[i] << ' ';
    // }
    // cout << endl;

    int test;
    cin >> test;
    while(test--){
        int a, b;
        int x, y;
        int k;
        cin >> a >> b >> x >> y >> k;
        a = n - a + 1;
        x = n - x + 1;
        if (b > y){
            swap(a, x);
            swap(b, y);
        }
        
        int beginY = (a - 1) % k + 1;
        int minCave = get(1,1,m,b,y);
        
        // cout << beginY << " " << minCave << endl;

        if (abs(a - x) % k != 0 or abs(b - y) % k != 0){
            cout << "NO" << endl;
            continue;
        }
        if (beginY <= minCave){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        

    }

    return 0;
}