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

vector<int> z_algorithm(string& s) {
  int l = 0;
  int r = 0;
  vector<int> z(s.size());
  int n = s.size();
  for (int i = 1; i < s.size(); i++) {
    if (i > r) {
      l = i;
      r = i;
      while (r < n && s[r - l] == s[r]) {
        r++;
      }
      z[i] = r - l;
      r--;
    } else {
      int k = i - l;
      if (z[k] < r - i + 1) {
        z[i] = z[k];
      } else {
        l = i;
        while (r < n && s[r - l] == s[r]) {
          r++;
        }
        z[i] = r - l;
        r--;
      }
    }
  }
  return z;
}


int main () {
}
