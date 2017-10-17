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

  vector<string> lines;
  string line;
  int m = 0;
  while (getline(cin, line)) {
    m = max(m, (int) line.size());
    lines.push_back(line);
  }
  m += 2;

  for (int i = 0; i < m; i++) {
    printf("*");
  }
  printf("\n");
  bool left = false;
  for (int i = 0; i < lines.size(); i++) {
    printf("*");
    int total_left = m - lines[i].size() - 2;
    int left_padding = total_left / 2 + (left && total_left % 2);
    int right_padding = total_left / 2 + (!left && total_left % 2);
    if (total_left % 2 == 1) {
      left = !left;
    }
    for (int j = 0; j < left_padding; j++) {
      printf(" ");
    }
    printf("%s", lines[i].c_str());
    for (int j = 0; j < right_padding; j++) {
      printf(" ");
    }
    printf("*\n");
  }

  for (int i = 0; i < m; i++) {
    printf("*");
  }

}
