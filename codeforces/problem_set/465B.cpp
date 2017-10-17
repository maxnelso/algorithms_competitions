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
  int n;
  scanf("%d", &n);
  vector<int> letters;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    letters.push_back(a);
  }
  int count = 0;
  if (find(letters.begin(), letters.end(), 1) == letters.end()) {
    count = 0;
  } else {
    int start = find(letters.begin(), letters.end(), 1) - letters.begin();
    count = 1;
    for (int i = start + 1; i < letters.size(); ++i) {
      if (letters[i] == 1) {
        count += min(2, i - start);
        start = i;
      }
    }
  }
  printf("%d", count);
}
