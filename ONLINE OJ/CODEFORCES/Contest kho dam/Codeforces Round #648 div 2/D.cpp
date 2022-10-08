#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;


const int N = 55;
int inf = 1e16;
int mod = 1e9 + 7;

int n, m;
char arr[N][N];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool valid(int i, int j) { return i >= 1 && i <= n && j >= 1 && j <= m; }
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
      cin >> (arr[i] + 1);
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (arr[i][j] == 'B') {
          for (int k = 0; k < 4; k++) {
            int ni = i + dir[k][0];
            int nj = j + dir[k][1];
            if (valid(ni, nj) && arr[ni][nj] == '.')
              arr[ni][nj] = '#';
          }
        }
      }
    }

    queue <ii> myQueue;
    bool visited[n + 5][m + 5];
    memset(visited, false, sizeof(visited));
    if (arr[n][m] == '.') {
      myQueue.push({n, m});
      visited[n][m] = true;
    }
    while (!myQueue.empty()) {
      pair curr = myQueue.front();
      myQueue.pop();
      for (int k = 0; k < 4; k++) {
        int ni = curr.fi + dir[k][0];
        int nj = curr.se + dir[k][1];
        if (valid(ni, nj) && !visited[ni][nj] && arr[ni][nj] != '#') {
          myQueue.push({ni, nj});
          visited[ni][nj] = true;
        }
      }
    }
    bool good = true;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if ((arr[i][j] == 'G' && !visited[i][j]) or
            (arr[i][j] == 'B' && visited[i][j])) {
          good = false;
          break;
        }
      }
    }
    cout << (good ? "Yes" : "No") << endl;
  }

  return 0;
}