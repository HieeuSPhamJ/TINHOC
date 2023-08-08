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

map <ii,int> cnt;
int dd[maxN];
int notprime[maxN];
int nxt[maxN];

int d(int x){
	unordered_set <int> s;
	s.insert(1);
	s.insert(x);
	while(nxt[x]){
		s.insert(x / nxt[x]);
		cout << x / nxt[x] << endl;
		x = nxt[x];
	}
	return s.size();
}

void init(){
    notprime[0] = notprime[1] = 1;
    for (int i = 2; i < maxN; i++){
            for (int j = 2 * i; j < maxN; j += i){
                notprime[j] = 1;
                nxt[j] = i;
            }
        }
    }
	for (int i = 2; i < maxN; i++){
		if (nxt[i] == 0){
			nxt[i] = 1;
		}
	}
}
ii mini(int x, int y){
    int gcd = __gcd(x,y);
    x /= gcd;
    y /= gcd;
    return {x,y};
}

signed main(){
	freopen("input.inp", "r", stdin);
	freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    init();
	cout << d(12) << endl;
    // for (int i = 1; i <= n; i++){
    //     dd[i] = d(i);
    //     cnt[mini(i, dd[i])]++;
    //     cout << i << ": " << dd[i] << endl;
    // }
    int res = 0;
    int resdup = 0;
    for (int i = 1; i <= n; i++){
        ii t = mini(k * dd[i],  i);
        int x = cnt[t];
        if (k * dd[i] * dd[i] == i * i){
            x--;
            resdup++;
        }
        res += x;
    }
    cout << res / 2 + resdup << endl;

    return 0;
}

/*

*/