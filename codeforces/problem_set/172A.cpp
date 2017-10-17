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
  int n;
  scanf("%d", &n);
  vector<string> numbers;
  for (int i = 0; i < n; ++i) {
    char c[256];
    scanf("%s", c);
    string s(c);
    numbers.push_back(s);
  }
  int count = 0;
  for (int i = 0; i < numbers[0].size(); ++i) {
    bool good = true;
    for (int j = 0; j < numbers.size() - 1; ++j) {
      if (numbers[j][i] != numbers[j+1][i]) {
        good = false;
        break;
      }
    }
    if (!good) {
      break;
    }
    count++;
  }
  printf("%d", count);
  setvbuf(stdout, NULL, _IONBF, 0);
}
