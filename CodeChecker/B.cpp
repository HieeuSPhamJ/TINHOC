#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 3e5 + 1;
const int MAX_VAL = 31 + 1;

int n;
int a[MAX_N];
int lastAns;
int ST[MAX_VAL][MAX_N << 2];
int lazy[MAX_VAL][MAX_N << 2];
int currCnt[MAX_VAL];

void down(int i, int id, int l, int r) {
    if (!lazy[i][id]) return;
    int k = lazy[i][id];

    if (k == 1) {
        ST[i][id << 1] = ST[i][id << 1 | 1] = 0;
    }
    else {
        int mid = (l + r) >> 1;
        ST[i][id << 1] = mid - l + 1;
        ST[i][id << 1 | 1] = r - mid;
    }

    lazy[i][id << 1] = k;
    lazy[i][id << 1 | 1] = k;

    lazy[i][id] = 0;
}

void update(int i, int id, int l, int r, int u, int v, int val) {
    if (u > r || v < l) return;

    if (u <= l && r <= v) {
        if (val) {
            ST[i][id] = r - l + 1;
        }
        else {
            ST[i][id] = 0;
        }
        lazy[i][id] = val + 1;
        return;
    }

    int mid = (l + r) >> 1;
    down(i, id, l, r);
    update(i, id << 1, l, mid, u, v, val);
    update(i, id << 1 | 1, mid + 1, r, u, v, val);

    ST[i][id] = ST[i][id << 1] + ST[i][id << 1 | 1];
}

int get(int i, int id, int l, int r, int u, int v) {
    if (u > r || v < l) return 0;

    if (u <= l && r <= v) {
        return ST[i][id];
    }

    int mid = (l + r) >> 1;
    down(i, id, l, r);
    return get(i, id << 1, l, mid, u, v) + get(i, id << 1 | 1, mid + 1, r, u, v);
}

signed main() {
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(a[i], 1, 1, n, i, i, 1);
    }

    int numCases = 0;
    cin >> numCases;
    for (int testCase = 1; testCase <= numCases; testCase++) {
        char type;
        cin >> type;

        int x, y;
        cin >> x >> y;

        if (x > y) swap(x, y);

        if (type == '1') {
            int type;
            cin >> type;

            for (int val = 0; val <= 30; val++) {
                currCnt[val] = get(val, 1, 1, n, x, y);
                update(val, 1, 1, n, x, y, 0);
            }

            int i = x;
            int step = 1, currVal = 0;
            if (type == 2) step = -1, currVal = 30;

            while (i <= y) {
                if (currCnt[currVal]) {
                    update(currVal, 1, 1, n, i, i + currCnt[currVal] - 1, 1);
                }
                i += currCnt[currVal];
                currVal += step;
            }
        }
        else {
            for (int val = 0; val <= 31; val++) {
                if (!get(val, 1, 1, n, x, y)) {
                    cout << val << '\n';
                    lastAns = val;
                    break;
                }
            }
        }
    }

    return 0;
}

/*


*/
