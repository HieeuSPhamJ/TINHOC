// BAI47QL
// input: n 
// Output: liệt kê các dãy dấu '(' và ')' thỏa đk trong bt toán học

// Vector nghiệm: X[1], ..., X[2n];
// Tập ứng cử viên S ={'(', ')'}
// Đk: thỏa đk trong bt toán học
//Hàm quay lui
#include <bits/stdc++.h>
using namespace std;
int n;
char X[50];
bool NgoacDung(){
	int d=0;
	for (int i=1; i<=2*n; i++){
		if (X[i]=='(') d+=1;
		else d-=1;
		if (d<0) return false;
	}
	return d==0;
}
void GhiNghiem(){
	if (!NgoacDung()) return;
	for (int i=1; i<=2*n; i++) cout << X[i];
	cout << endl;
}
void Try(int i){
	for (char j = '('; j<=')'; j++){
		X[i] = j;
		if (i==2*n) GhiNghiem();
		else Try(i+1);
	}
}
//Hàm main
int main(){
	freopen("BAI47QL.INP", "r", stdin);
	freopen("BAI47QL.OUT", "w", stdout);
	cin >> n;
	Try(1);
	return 0;
}