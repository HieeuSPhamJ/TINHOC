#include<bits/stdc++.h>
#define ii pair <int,int>
#define va first
#define id second
#define int long long
using namespace std;

const int inf = 1e18;
const int maxN = 2 * 1e5 + 10;
int seg[maxN + 4];
int a[maxN];
int n;

void update(int index, int val) {
    for (int i = index; i <= n; i += i & (-i)) {
        seg[i] += val;
    }
}

int get(int index) {
    int res = 0;
    for (int i = index; i > 0; i -= i & (-i)) {
        res += seg[i];
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        cin >> n;
        for (int i = 0; i <= n + 10; i++){
            seg[i] = 0;
        }
        vector <int> lists;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if (a[i] < i){
                lists.push_back(i);
                // cout << a[i] << ' ' << i << endl;
            }
        }

        int count = 0;

        for (auto i: lists){
            count += get(a[i] - 1);
            update(i, 1);
        }

        cout << count;
        cout << endl;
    }
    return 0;
}
