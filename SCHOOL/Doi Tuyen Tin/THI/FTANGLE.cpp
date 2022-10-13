#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;

bool cmp(ii a, ii b){
    return a.fi * b.se < a.se * b.fi;
}

signed main(){
    //freopen("FTANGLE.INP", "r", stdin);
    //freopen("FTANGLE.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <ii> func;
    for (int i = 1; i <= n; i++){
        int a, b, trash;
        cin >> a >> b >> trash;
        func.push_back({a,b});
    }   

    sort(func.begin(), func.end(), cmp);

    int ans = 0;

    int left = 0;
    int right = 0;
    
    for (int i = 0; i < n; i++){
        while(cmp(func[left], func[i])){
            left++;
        }
        while(right < n and !cmp(func[i], func[right])){
            right++;
        }
        (ans += (left * (n - right)) % mod) %= mod;
    }
    cout << ans << endl;

    return 0;
}