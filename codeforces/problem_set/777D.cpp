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
#include <iterator>
#include <unordered_map>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int main () {
  int n;
  scanf("%d", &n);
  vector<string> hashtags;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    hashtags.push_back(s);
  }
  for (int i = hashtags.size() - 2; i >= 0; i--) {
    string& a = hashtags[i];
    string& b = hashtags[i+1];
    int slice_index = -1;
    for (int j = 0; j < max(a.size(), b.size()); j++) {
      if (j >= a.size()) {
        slice_index = j;
        break;
      }
      if (a[j] < b[j]) {
        break;
      }
      if (a[j] > b[j]) {
        slice_index = j;
        break;
      }
    }
    if (slice_index != -1) {
      a.erase(slice_index);
    }
  }

  for (int i = 0; i < hashtags.size(); i++) {
    printf("%s\n", hashtags[i].c_str());
  }
}
