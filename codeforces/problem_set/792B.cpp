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
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> kids;
  for (int i = 0; i < n; i++) {
    kids.push_back(i);
  }

  vector<int> steps;
  for (int i = 0; i < k; i++) {
    int a;
    scanf("%d", &a);
    steps.push_back(a);
  }

  int leader = 0;
  for (int i = 0; i < k; i++) {
    int diff = steps[i] % kids.size();
    int index = (leader + diff) % kids.size();
    printf("%d ", kids[index] + 1);
    kids.erase(kids.begin() + index);
    leader = index % kids.size();
  }
}
