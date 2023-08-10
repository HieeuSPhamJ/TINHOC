#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

struct iii{
    int beg, l, r;
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        vector <iii> lists;
        for (int i = 1; i <= n; i++){
            int beg, l, r;
            cin >> beg >> l >> r;
            lists.push_back({beg,l,r});
        }
        int left = k;
        int right = k;
        int check = 1;
        int lastMin = 0;
        for (auto i: lists){
            int newLeft = left - abs(i.beg - lastMin);
            int newRight = right + abs(i.beg - lastMin);
            // cout << i.beg << ": " << newLeft << " " << newRight << "|" << i.l << " " << i.r << endl;
            if (i.r < newLeft or newRight < i.l){
                check = 0;
                break;
            }
            lastMin = i.beg;
            left = max(newLeft, i.l);
            right = min(newRight, i.r);
            
            // cout << left << " " << right << endl;
        }
        if (check == 1){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}