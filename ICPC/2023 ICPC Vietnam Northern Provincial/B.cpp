#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rec pair<ii,ii>
using namespace std;

bool cmp(rec a, rec b){
    return a.fi.fi < b.fi.fi;
}



signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> k >> n;
    vector <rec> ls;
	int x1 = 0, y1 = 0;
    for (int i = 1; i <= n; i++){
        char type;
		int step;
		cin >> type >> step;

		if (type == 'E') {
			// Dong
            ls.push_back({{x1, x1 + k + step - 1},{y1, y1 + k - 1}});
            x1 = x1 + step;
			continue;
		}
		if (type == 'W') {
			// Tay
            ls.push_back({{x1 - step, x1 + k - 1},{y1, y1 + k - 1}});
            x1 = x1 - step;
			continue;
		}
		if (type == 'N') {
			// Bac
            ls.push_back({{x1,x1 + k - 1},{y1, y1 + k + step - 1}});
            y1 = y1 + step;
			continue;
		}
		if (type == 'S') {
			// Nam
            ls.push_back({{x1,x1 + k - 1},{y1 - step, y1 + k - 1}});
            y1 = y1 - step;
			continue;
		}

    }
    sort(all(ls), cmp);

    for (auto i: ls){
        cout << i.fi.fi << ' ' << i.fi.se << " " << i.se.fi << " " << i.se.se << endl;
    }
    
    return 0;
}