#include <bits/stdc++.h>
using namespace std;

ifstream fin("rufe.in");
ofstream fout("rufe.out");

int64_t sumAll(int64_t n) {
   return n * (n + 1) / 2;
}

int64_t sumOdd(int64_t n) {
   return sumAll(n + 1) - 2 * sumAll((n + 1) / 2);
}

int main() {
   int64_t m, n, a, b, k;
   fin >> m >> n >> a >> b >> k;

   auto getArea = [&](int64_t len) {
       int64_t area = 2 * sumOdd(2 * len - 1) + 2 * len + 1;
       if (a - len < 1) area -= sumOdd(2 * len + 1 - 2 * a);
       if (a + len > m) area -= sumOdd(2 * len + 1 - 2 * (m - a + 1));
       if (b - len < 1) area -= sumOdd(2 * len + 1 - 2 * b);
       if (b + len > n) area -= sumOdd(2 * len + 1 - 2 * (n - b + 1));

       if (len >= a + b) area += sumAll(len - (a + b) + 1);
       if (len >= a + n - b + 1) area += sumAll(len - (a + n - b + 1) + 1);
       if (len >= m - a + 1 + b) area += sumAll(len - (m - a + 1 + b) + 1);
       if (len >= m - a + 1 + n - b + 1) area += sumAll(len - (m - a + 1 + n - b + 1) + 1);
       return area;
   };

   int64_t lo = 0, hi = m + n;
   while (hi - lo > 1) {
       int64_t md = (lo + hi) / 2;
       if (m * n - getArea(md) < k)
           hi = md;
       else
           lo = md;
   }
   fout << hi << '\n';
   return 0;
}