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

bool works(string& trip, string& before, string& after) {
  size_t before_pos = trip.find(before);

  if (before_pos == string::npos) {
    return false;
  }

  size_t after_pos = trip.find(after, before_pos + before.size());
  if (after_pos == string::npos) {
    return false;
  }

  return true;
}

int main () {
  char c[1000000];
  scanf("%s", c);
  string trip(c);
  string reverse_trip(trip);
  reverse(reverse_trip.begin(), reverse_trip.end());
  char beforec[100005];
  scanf("%s", beforec);
  string before(beforec);
  char afterc[100005];
  scanf("%s", afterc);
  string after(afterc);

  bool f = works(trip, before, after);
  bool b = works(reverse_trip, before, after);
  if (f && b) {
    printf("both");
  } else if (f) {
    printf("forward");
  } else if (b) {
    printf("backward");
  } else {
    printf("fantasy");
  }
}
