#include <iostream>
#include <map>

using namespace std;

string s;
map<string, bool> m;
bool a[50];

void backTracking(int d) {
	if (d > s.size()) {
		string temp = "";
		for (int i = 1; i <= s.size(); i++) {
			if (a[i]) {
				temp += s[i - 1];
			}
		}

		if (!m[temp] && temp.size()) {
			m[temp] = true;
			cout << temp << "\n";
		}
	}
	else {
		for (int i = 0; i <= 1; i++) {
			a[d] = i;
			backTracking(d + 1);
		}
	}
}

int main() {
	freopen("BAI46QL.INP", "r", stdin);
	freopen("BAI46QL.OUT", "w", stdout);

	cin >> s;

    backTracking(1);

	return 0;
}