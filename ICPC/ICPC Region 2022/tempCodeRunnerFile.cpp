#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int lists[30];

signed main() {
	// freopen("input.inp", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int test;
	cin >> test;
	while(test--){
		string s;
		cin >> s;
		int k;
		cin >> k;

		if (k <= 1){
			cout << "OH NO!" << endl;
			continue;
		}

		for (int i = 0; i <= 26; i++){
			lists[i] = 0;
		}

		for (int i = 0; i < s.length(); i++){
			lists[s[i] - 'a']++;
		}

		int n = s.length();

		vector <int> tempAns;
		int last = 0;
		while(tempAns.size() < n){
			// cout << "Try: " << tempAns.size() + 1 << " " << last <<endl;
			for (int i = 0; i < 26; i++){
				while (lists[i]){	
					// if (tempAns.empty() == 0 and last + (tempAns.back() == i) >= k){
					// 	goto b1;
					// }
					if (tempAns.empty() or tempAns.back() == i){
						last++;
					}
					else{
						last = 1;
					}
					if (last >= k){
						goto b2;
					}
					tempAns.push_back(i);
					lists[i]--;		
					// cout << last << endl;
					if (last >= k - 1){
						for (int j = i + 1; j <= 25; j++){
							if (lists[j]){
								lists[j]--;
								tempAns.push_back(j);
								last = 1;
								goto b1;
							}
						}
						goto b2;
					}		

				}
			}
			b1:;
		}
		b2:;


		deque <int> temp;

		// for (int i = 0; i <= 25; i++){
		// 	cout << lists[i] << " ";
		// }
		// cout << endl;

		for (int i = 26; i >= 0; i--){
			while (lists[i]){
				temp.push_back(i);
				lists[i]--;
			}
		}


		// for (auto i: tempAns){
		// 	cout << i << " ";
		// }
		// cout << endl;
		// for (auto i: temp){
		// 	cout << i << " ";
		// }
		// cout << endl;

		deque <int> ans;

		last = 0;
		int check = 0;
		while((int)ans.size() < n){
			// cout << "Index " << ans.size() + 1 << " " << last << endl;	
			// for (auto i: tempAns){
			// 	cout << i << " ";
			// }
			// cout << endl;

			// for (auto i: temp){
			// 	cout << i << " ";
			// }
			// cout << endl;
			if (tempAns.empty()){
				// cout << "front temp (lists empty)" << endl;
				if (last + (ans.front() == temp.front()) >= k){
					check = 1;
					break;
				}
				ans.push_front(temp.front());
				temp.pop_front();
			}
			else if (temp.empty()){
				// cout << "front lists (temp empty)" << endl;
				if (last + (ans.front() == tempAns.back()) >= k){
					check = 1;
					break;
				}
				ans.push_front(tempAns.back());
				tempAns.pop_back();
			}
			else if (tempAns.back() == temp.front()){

				// cout << "front lists" << endl;
				if (last >= k - 1){
					check = 1;
					break;
				}
				ans.push_front(tempAns.back());
				tempAns.pop_back();
			}
			else {
				if (last + (ans.front() == temp.front()) < k){		
					// cout << "front temp" << endl;
					ans.push_front(temp.front());
					temp.pop_front();
				}
				else{
					// cout << "front lists" << endl;
					ans.push_front(tempAns.back());
					tempAns.pop_back();

				}
			}

			if (ans.size() == 1){
				last = 1;
			}
			else{
				if (ans[0] == ans[1]){
					last++;
				}
				else{
					last = 1;
				}
			}

			// for (auto i: ans){
			// 	cout << i << " ";
			// }
			// cout << endl;

		}

		if (check == 1 or ans.size() < n){
			cout << "OH NO!" << endl;
			continue;
		}

		for (auto i: ans){
			cout << char(i + 'a');
		}
		cout << endl;
	}



	return 0;
}

/*
1
aaaabbbb
3

*/