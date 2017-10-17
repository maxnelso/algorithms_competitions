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
  string heidi = "heidi";
  int heidi_i = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == heidi[heidi_i]) {
      heidi_i++;
    }
    if (heidi_i >= heidi.size()) {
      printf("YES");
      return 0;
    }
  }
  printf("NO");
  return 0;
}
