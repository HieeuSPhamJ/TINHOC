#include<bits/stdc++.h>
using namespace std;

string s;
long long ans = 0;

void backTracking(int d, string num) {
	if (d == (int) s.size()) {
		bool check = false;
		string temp = num;
		while (temp[0] == '0') {
			check = true;
			temp.erase(0, 1);
		}
		if (temp != "" and !check) {
			int sum = 0;
			for (int i = 0; i < (int) temp.size(); i++) {
				sum += temp[i] - '0';
			}
			ans += (sum % 3 == 0);
		}
	}
	else {
		backTracking(d + 1, num);
		backTracking(d + 1, num + s[d]);
	}
}

int main() {
	freopen("DIV3.INP", "r", stdin);
	freopen("DIV3.OUT", "w", stdout);
	cin >> s;
	backTracking(0, "");
	cout << ans;
	return 0;
}