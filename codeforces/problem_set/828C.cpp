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
  int n;
  scanf("%d", &n);
  string current((int) 10e7, '*');
  int end = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      int index;
      scanf("%d", &index);
      index--;
      end = max(end, index + (int) s.size());
      for (int z = 0; z < s.size(); z++) {
        current[z + index] = s[z];
      }
    }
  }

  for (int i = 0; i < end; i++) {
    if (current[i] == '*') {
      printf("a");
    } else {
      printf("%c", current[i]);
    }
  }
}
