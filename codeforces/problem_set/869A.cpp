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
  set<int> seen;
  vector<int> as;
  vector<int> bs;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    as.push_back(a);
    seen.insert(a);
  }
  for (int i = 0; i < n; i++) {
    int b;
    scanf("%d", &b);
    bs.push_back(b);
    seen.insert(b);
  }
  int out = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (seen.find(as[i] ^ bs[j]) != seen.end()) {
        out++;
      }
    }
  }
  if (out % 2 == 0) {
    printf("Karen");
  } else {
    printf("Koyomi");
  }
}
