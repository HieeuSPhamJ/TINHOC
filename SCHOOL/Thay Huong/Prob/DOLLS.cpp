#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;
const int inf = 1e18;

int n,p;
int a[maxN];
int bit[maxN];

void update(int i, int v){
    while(i <= n){
        bit[i] += v;
        i += (i & (-i));
    }
}

int get(int i){
    int res = 0;
    while(i){
        res += bit[i];
        i -= (i & (-i));
    }
    return res;
}

void nenso(vector <int> &ls){
    sort(all(ls));
	ls.erase(unique(all(ls)), ls.end());
	for (int i = 0; i <= n; i++){
		a[i] = lower_bound(all(ls), a[i]) - ls.begin();
        a[i]++;
	}
}

signed main(){
    freopen("DOLLS.INP", "r", stdin);
    freopen("DOLLS.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
    vector <int> ls;
	cin >> p;
	int res = 0;
	for (int i = 1; i <= n; i++){
		a[i] -= p;
		a[i] += a[i - 1];
		res += a[i] >= 0;
		ls.push_back(a[i]);
	}

	nenso(ls);

	for (int i = 1; i <= n; i++){
		res += get(a[i]);
		update(a[i],1);
	}

	cout << res;
    return 0;
}