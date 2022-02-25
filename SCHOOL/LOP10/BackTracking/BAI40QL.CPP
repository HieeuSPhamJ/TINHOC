#include <bits/stdc++.h>
using namespace std;
int x=0, n;
bool cn=false;

bool NTO(int a){
	for (int i=2; i*i <=a; i++){
		if (a % i == 0) return false;
	}
	return a>1;
}

void Try(int i){
	for (int j = 0; j<=9; j++){
		if (NTO(x*10+j)){
			x = x * 10 + j;
			if (i==n) {
				cout << x << endl;
				cn = true;
			} else Try(i+1);
			x=x/10;
		}
	}
}

int main(){
	freopen("BAI40QL.INP", "r", stdin);
	freopen("BAI40QL.OUT", "w", stdout);
	cin >> n;
	Try(1);
	if (!cn) cout << -1;
	return 0;
}