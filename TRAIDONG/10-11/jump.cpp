#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define id se
#define value fi
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;
const int inf = 1e18;

int n, test;
ii seg[maxN * 4];
int a[maxN];

ii MAX(ii s1, ii s2){
    if (s1.value == s2.value){
        if (s1.id > s2.id){
            return s2;
        }
        return s1;
    }
    if (s1.value > s2.value){
        return s1;
    }
    return s2;
}

void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i].value += val;
        seg[i].id = index;
        return;
    }
    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);
    seg[i] = MAX(seg[2 * i], seg[2 * i + 1]);
}

ii get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return {-inf, -inf};
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    ii t1 = get(2 * i, left, mid, _left, _right);
    ii t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return MAX(t1,t2);

}

int solve(int x, int y){
    // cout << "Sol: " << x << " " << y << endl;
    ii range = get(1,1,n,x + 1, y - 1);
    if (x + 1 == y and a[x] < a[y]){
        // cout << "just1" << " ";
        return 1;
    }
    if (range.value >= a[y] or range.value <= a[x]){
        // cout << "ngu" << endl;
        return -1;
    }
    
    int left = solve(x, range.id);
    if (left != -1){
        // cout << "ok" << endl;
        return left + 1; 
    }
    return -1;


}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        update(1,1,n,i,a[i]);
    }
    while(test--){
        cout << "Test" << endl;
        int a, b;
        cin >> a >> b;
        a++;
        b++;
        int goright = solve(a,b);
        // int goleft = solveleft
        cout <<  << endl;
    }
    return 0;
}