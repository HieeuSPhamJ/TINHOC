#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define all(x) x.begin(), x.end()
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;

struct ant{
    int x,w;
};  

int n, L, test;
vector <ant> a[3];
int prefix[maxN];

bool cmp(ant a, ant b){
    return a.x < b.x;
}

int calLeft(int time){
    int left = 0;
    int right = a[0].size() - 1;
    int ans = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        if (a[0][mid].x > time){
            right = mid - 1;
        }
        else{
            left = mid + 1;
            ans = mid;
        }
    }

    return ans + 1;
}


int calRight(int time){
    int left = 0;
    int right = a[1].size() - 1;
    int ans = 0;
    while(left <= right){
        int mid = (left + right) / 2;
        if (L - a[1][mid].x > time){
            left = mid + 1;
        }
        else{
            right = mid - 1;
            ans = a[1].size() - mid;
        }
    }
    return ans;
}

signed main(){
    // freopen("ANTMOVE.INP", "r", stdin);
    // freopen("ANTMOVE.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> L >> test;
    for (int i = 1; i <= n; i++){
        int x, w, d;
        cin >> x >> w >> d;
        a[d].push_back({x,w});
        a[2].push_back({x,w});
    }
    sort(a[0].begin(), a[0].end(), cmp);
    sort(a[1].begin(), a[1].end(), cmp);
    sort(a[2].begin(), a[2].end(), cmp);

    for (int i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + a[2][i - 1].w;
    }
    // for (int i = 1; i <= n; i++){
    //     cout << prefix[i] << " ";
    // }
    // cout << endl;
    while(test--){
        int time;
        cin >> time;
        int left = calLeft(time);
        int right = calRight(time);
        // if (left >= n or right >= n){
        //     cout << prefix[n] << " ";
        //     continue;
        // }
        // cout << left << " " << right << endl;
        cout << prefix[left] + (prefix[n] - prefix[n - right]) << " ";
        // cout << endl;
    }

    return 0;
}