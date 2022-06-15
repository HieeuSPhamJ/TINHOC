#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

const int maxN = 3 * 1e5 + 1;

int a[maxN];
int seg[maxN * 4];
map <int, vector<int>> listMap;

void update(int i, int left, int right, int val, int index){
    // cout << i << ' ' << left << ' ' << right << endl;
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i] = val;
        // cout << "#" << endl;
        return;
    }

    int mid = (left + right) / 2;
    update(2 * i, left, mid, val, index);
    update(2 * i + 1, mid + 1, right, val, index);
    seg[i] = __gcd(seg[2 * i], seg[2 * i + 1]);
}

int get(int i, int left, int right, int _left, int _right){
    if (_right < left or right < _left){
        return 0;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    return __gcd(get(2 * i, left, mid, _left, _right), get(2 * i + 1, mid + 1, right, _left, _right));


}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        // cout << inp << ' ' << i << endl;
        // cout << "#";
        update(1, 1, n, a[i], i);
    }

    for (int i = 1; i <= n; i++){
        int temp = a[i];
        listMap[a[i]].push_back(i);
    }

    int test;
    cin >> test;


    while(test--){
        // cout << "Test Case:" << endl;3
        int l, r;
        cin >> l >> r;

        int target = get(1, 1, n, l, r);

        // cout << target << endl;

        // vector <int> listMap[target] = listMap[target];
        // for (auto i: listMap[target]){
        //     cout << i << ' ';
        // }
        // cout << endl;

        int left = 0;
        int right = (int)(listMap[target].size()) - 1;
        int _left = -1;
        int _right = -1;
        
        while (left <= right){
            int mid = (left + right) / 2;
            // cout << left << ' ' << mid << ' ' << right << endl;
            if (listMap[target][mid] >= l){
                right = mid - 1;
                _left = mid;
            }
            else{
                left = mid + 1;
            }
        }

        
        // cout << "--" << endl;

        left = 0;
        right = (int)(listMap[target].size()) - 1;

        while (left <= right){
            int mid = (left + right) / 2;
            // cout << left << ' ' << mid << ' ' << right << endl;
            if (listMap[target][mid] <= r){
                left = mid + 1;
                _right = mid;
            }
            else{
                right = mid - 1;
            }
        }
        
        int count = 0;

        // cout << _left << ' ' << _right << endl;

        if ((_left != -1 and _right != -1) and a[listMap[target][_left]] == target and a[listMap[target][_right]] == target){
            count = _right - _left + 1;
        }

        // cout << count << endl;

        cout << (r - l + 1) - count << endl;

    }

    return 0;
}