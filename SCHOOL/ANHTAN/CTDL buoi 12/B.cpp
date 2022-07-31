#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define x first
#define value second
#define int long long
using namespace std;

const int inf = 1e18;
const int maxN = 1e5 + 10;

int n, d;
ii a[maxN];
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

    seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    
}

int get(int i, int left, int right, int _left, int _right){
    if (_right < left or right < _left){
        return -inf;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;
    return max(get(2 * i, left, mid, _left, _right), get(2 * i + 1, mid + 1, right, _left, _right));

}

int binarySuckLeft(int left, int right, int i){
    int ans = i;
    while(left <= right){
        int mid = (left + right) / 2;
        if (abs(a[mid].x - a[i].x) <= d){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return ans;
}

int binarySuckRight(int left, int right, int i){
    int ans = i;
    while(left <= right){
        int mid = (left + right) / 2;
        if (abs(a[mid].x - a[i].x) <= d){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> d;
    
    for (int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].value;
    }

    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++){
        update(1, 1, n, i, a[i].value);
    }

    int count = 0;

    for (int i = 1; i <= n; i++){
        int left = binarySuckLeft(1, i, i);
        int right = binarySuckRight(i, n, i);
        
        int maxPetrolLeft = get(1, 1, n, left, i);
        int maxPetrolRight = get(1, 1, n, i, right);
        if (a[i].value * 2 <= maxPetrolLeft and a[i].value * 2 <= maxPetrolRight){
            count++;
        }
    }

    cout << count;

    return 0;
}