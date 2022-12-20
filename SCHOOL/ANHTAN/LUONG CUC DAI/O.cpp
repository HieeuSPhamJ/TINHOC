#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 31;

int n;
int a[maxN][maxN];
int temp[maxN][maxN];
int win[maxN];
int adu[maxN];
int wintemp[maxN];

bool ok(int i){
    for (int j = 1; j <= n; j++){
        if (adu[i] < adu[j]){
            return 0;
        }
    }
    return 1;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
	for (int i = 1; i <= n; i++){
	    for (int j = 1; j <= n; j++){	
            cin >> a[i][j];
            win[i] += (a[i][j] == 1 and i != j);
        }
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			adu[j] = win[j];
			wintemp[j] = 0;
			for (int k = 1; k <= n; k++){
                temp[j][k] = a[j][k];
            }
		}

		for (int j = 1; j <= n; j++) {
			if (i == j or a[i][j] != 2){
                continue;
            }
			temp[i][j] = 1;
			temp[j][i] = 0;
			adu[i]++;
		}

		wintemp[i] = 1;

		for (int x = 1; x < n; x++){
			int j = 0;
            int ans = n + 1;
			for (int k = 2; k <= n; k++){
			    if (ans > adu[k] and !wintemp[k]){
                    ans = adu[k];
                    j = k;
                }
            }

			wintemp[j] = 1;
            
			if (adu[i] < adu[j]){
                break;
            }

			for (;adu[j] < adu[i];){
				int k = 0;
                int ans = 0;
				for (int p = 1; p <= n; p++)
				if (ans < adu[p] and temp[j][p] == 2){
                    ans = adu[p];
                    k = p;
                }
				if (k == 0){
                    break;
                }
				adu[j]++;
				temp[j][k] = 1;
				temp[k][j] = 0;
			}

			for (int k = 1; k <= n; k++) {
				if (k == i or k == j){
                    continue;
                }
				if (temp[j][k] == 2) {
					adu[k]++;
					temp[j][k] = 0;
					temp[k][j] = 1;
				}
			}
		}

		
        cout << ok(i);
	}


    return 0;
}