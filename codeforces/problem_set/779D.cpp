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
  char a[200005];
  char b[200005];
  scanf("%s", a);
  string t(a);
  scanf("%s", b);
  string p(b);
  vector<int> permutation;
  for (int i = 0; i < t.size(); i++) {
    int x;
    scanf("%d", &x);
    permutation.push_back(x);
  }
  map<char, int> t_counts;
  for (int i = 0; i < t.size(); i++) {
    t_counts[t[i]]++;
  }
  map<char, int> p_counts;
  for (int i = 0; i < p.size(); i++) {
    p_counts[p[i]]++;
  }
  for (int i = 0; i < t.size(); i++) {
    char c = t[permutation[i]];
    t_counts[c]--;
  }

}
