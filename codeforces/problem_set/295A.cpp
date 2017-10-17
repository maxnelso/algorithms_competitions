#include <bitset>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <iterator>
#include <unordered_map>

using namespace std;

vector<long long> nums;

struct operation {
  long long l;
  long long r;
  long long d;
};

int main () {
  long long n, m, k;
  cin >> n >> m >> k;

  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    nums.push_back(a);
  }

  vector<operation> operations;
  for (long long i = 0; i < m; i++) {
    long long l, r, d;
    cin >> l >> r >> d;
    operation o;
    o.l = l - 1;
    o.r = r - 1;
    o.d = d;
    operations.push_back(o);
  }

  vector<long long> counts(m + 1);
  for (long long i = 0; i < k; i++) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    counts[x]++;
    counts[y + 1]--;
  }

  vector<long long> real_counts(n + 1);
  long long current = 0;
  for (long long i = 0; i < counts.size() - 1; i++) {
    current += counts[i];
    operation o = operations[i];
    real_counts[o.l] += o.d * current;
    real_counts[o.r + 1] -= o.d * current;
  }

  current = 0;
  for (long long i = 0 ; i < n; i++) {
    current += real_counts[i];
    nums[i] += current;
    cout << nums[i] << " ";
  }

}
