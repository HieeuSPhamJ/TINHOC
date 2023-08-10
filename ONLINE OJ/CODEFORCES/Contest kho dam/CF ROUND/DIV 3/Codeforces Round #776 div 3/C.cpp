#include<bits/stdc++.h>
#define ii pair <int,int>
#define i first
#define w second
#define ll long long
using namespace std;

bool cmp(ii a, ii b){
    return a.w < b.w;
}

map <int, int> indexMap;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        vector <ii> lists;

        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int weight, index;
            cin >> index >> weight;
            lists.push_back({index, weight});
            indexMap[index] = i;
        }

        sort(lists.begin(), lists.end(), cmp);
        
        vector <int> listsAns;

        int ans = 0;

        for (int i = 0; i < 2 * n; i++){
            listsAns.push_back(lists[i].i);
            ans += lists[i].w;
        }

        sort(listsAns.begin(), listsAns.end());

        cout << ans << endl;

        for (int i = 0; i < n; i++){
            cout << indexMap[listsAns[i]] << ' ' << indexMap[listsAns[2 * n - 1- i]] << endl;
        }

        cout << endl;
    }
    return 0;
}