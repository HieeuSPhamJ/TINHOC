#include <iostream>

using namespace std;

string s, a;
int count[26];

void backTracking(int d) { 
	if (d == (int) a.size()) {
		cout << s << "\n";
	}
	else {
		for (int i = 0; i < 26; i++){
			if (count[i]) {
				s += char(i + 'A');
				count[i]--;
				backTracking(d + 1);
				count[i]++;
				s.erase(s.size() - 1, 1);
			}
		}
	}
}

int main() {
	freopen("BAI49QL.INP", "r", stdin);
	freopen("BAI49QL.OUT", "w", stdout);

	cin >> a;

	for (int i = 0; i < (int) a.size(); i++) {
		count[a[i] - 'A']++;
	}

	backTracking(0);

	return 0;
}