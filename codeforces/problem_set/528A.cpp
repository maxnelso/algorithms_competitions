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
  int w, h, n;
  cin >> w >> h >> n;
  set<int> horizontals;
  horizontals.insert(0);
  horizontals.insert(h);
  set<int> verticals;
  verticals.insert(0);
  verticals.insert(w);
  multiset<int> horizontal_gaps;
  horizontal_gaps.insert(h);
  multiset<int> vertical_gaps;
  vertical_gaps.insert(w);
  for (int i = 0; i < n; i++) {
    char c;
    int cut;
    cin >> c >> cut;
    if (c == 'V') {
        set<int>::iterator low = verticals.upper_bound(cut);
        int big = *(low);
        low--;
        int small = *(low);
        int old_gap = big - small;
        verticals.insert(cut);
        vertical_gaps.erase(find(vertical_gaps.begin(), vertical_gaps.end(), old_gap));
        vertical_gaps.insert(big - cut);
        vertical_gaps.insert(cut - small);
    } else {
        set<int>::iterator low = horizontals.upper_bound(cut);
        int big = *(low);
        low--;
        int small = *(low);
        int old_gap = big - small;
        horizontals.insert(cut);
        horizontal_gaps.erase(find(horizontal_gaps.begin(), horizontal_gaps.end(), old_gap));
        horizontal_gaps.insert(big - cut);
        horizontal_gaps.insert(cut - small);
    }
    int out = *horizontal_gaps.rbegin() * *vertical_gaps.rbegin();
    cout << out << endl;
  }

}
