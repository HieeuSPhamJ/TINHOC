#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define id first
#define val second
#define int long long
using namespace std;

struct iii{
    int p,c,id;
};


const int maxN = 1e5 + 10;

vector <iii> lists;
vector <ii> ans;
priority_queue <int, vector <int>, greater <int>> deadPool;
int ta[maxN];
int tb[maxN];


bool cmp(iii a, iii b){
    return a.p < b.p;
}

signed main(){
    freopen("KILL.INP", "r", stdin);
    freopen("KILL.OUT", "w", stdout); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int size = 0;
    for (int i = 1; i <= n; i++){
        cin >> ta[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> tb[i];
    }

    for (int i = 1; i <= n; i++){
        lists.push_back({ta[i], tb[i], i});
    }

    sort(lists.begin(), lists.end(), cmp);

    int tempAns = 0;

    int sizePool = 0;

    for (auto i: lists){
        sizePool++;
        // cout << i.c << ' ';
        if (sizePool > k + 1){
            tempAns += i.c - deadPool.top();
            deadPool.pop();
            // cout << tempAns;
            ans.push_back({i.id, tempAns});
        }
        else{
            tempAns += i.c;
            // cout << tempAns;
            ans.push_back({i.id, tempAns});
        }
        // cout << endl;
        deadPool.push(i.c);
    }

    sort(ans.begin(), ans.end());

    for (auto i: ans){
        cout << i.val << ' ';
    }





    return 0;
}