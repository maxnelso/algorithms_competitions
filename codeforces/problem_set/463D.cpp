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
#include <iterator>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);

  int n, k;
  scanf("%d %d", &n, &k);
  vector<string> sequences;
  for (int i = 0; i < k; ++i) {
    string sequence = "";
    for (int j = 0; j < n; ++j) {
      int a;
      scanf("%d", &a);
      sequence += to_string(a);
    }
    sequences.push_back(sequence);
  }
  for (int i = 2; i < n; ++i) {
    for (int j = 0; j < n - i + 1; ++j) {
      string sub = sequence[0].substr(j, i);
    }
  }
}
