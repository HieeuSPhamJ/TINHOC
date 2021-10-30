#include<bits/stdc++.h>
using namespace std;


map<char,char> conv;

int main(){
	conv['A']='T';
	conv['T']='A';
	conv['C']='G';
	conv['G']='C';
	string n;
	cin>>n;
	for (int i=int(n.length()-1);i>=0;i--){
		cout<<conv[n[i]];
	}
return 0;
}