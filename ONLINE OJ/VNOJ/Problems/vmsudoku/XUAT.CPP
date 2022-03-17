#include <iostream>

using namespace std;

int main() {
	freopen("XUAT.INP", "r", stdin);
	freopen("XUAT.OUT", "w", stdout);

	for (int i = 1; i <= 9; i++) {
		string inp;
		cin >> inp;
		cout << "print('" << inp << "')" << endl; 
	}
}