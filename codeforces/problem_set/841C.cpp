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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int main () {
  int m;
  scanf("%d", &m);
  vector<int> A;
  vector<pair<int, int>> B;
  for (int i = 0; i < m; i++) {
    int a;
    scanf("%d", &a);
    A.push_back(a);
  }
  for (int i = 0; i < m; i++) {
    int a;
    scanf("%d", &a);
    B.push_back({a, i});
  }

  sort(A.rbegin(), A.rend());
  sort(B.begin(), B.end());

  vector<int> out(m);
  for (int i = 0; i < m; i++) {
    out[B[i].second] = A[i];
  }

  for (int i = 0; i < m; i++) {
    printf("%d ", out[i]);
  }
}
