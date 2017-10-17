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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  map<int, bool> seen;
  int n;
  scanf("%d", &n);
  int p;
  scanf("%d", &p);
  for (int i = 0; i < p; i++) {
    int a;
    scanf("%d", &a);
    if (seen.find(a) == seen.end()) {
      seen[a] = true;
    }
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int a;
    scanf("%d", &a);
    if (seen.find(a) == seen.end()) {
      seen[a] = true;
    }
  }
  if (seen.size() == n) {
    printf("I become the guy.");
  } else {
    printf("Oh, my keyboard!");
  }
}
