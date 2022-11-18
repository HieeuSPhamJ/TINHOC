#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e4;
const int maxPoint = 1e9;

int a[maxN];
int b[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    vector <int> worse;
    vector <int> best;
    for (int i = 1; i <= n; i++){
        best.push_back(maxPoint * a[i] - b[i]);
        worse.push_back(a[i] - maxPoint * b[i]);
    }
    sort(best.begin(),best.end());
    sort(worse.begin(),worse.end());

    for (auto i: best){
        cout << i << " ";
    }
    cout << endl;
    for (auto i: worse){
        cout << i << " ";
    }
    cout << endl;

    for (int i = 1; i <= n; i++){
        int maxVal = maxPoint * a[i] - b[i];
        int minVal = a[i] - maxPoint * b[i];
        cout << maxVal << " : " << minVal << " ";
        // cout << n - (upper_bound(best.begin(), best.end(), maxVal + 1) - best.begin()) + 1;
        // cout << " ";
        // cout << n - (upper_bound(worse.begin(), worse.end(), minVal + 1) - worse.begin()) + 1;
        cout << endl;
    }
    return 0;
}