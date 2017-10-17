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

vector<vector<string>> binary_strings;

void precompute() {
  vector<string> start = {"0", "1"};
  binary_strings.push_back(start);
  for (int i = 0; i < 13; i++) {
    vector<string> strings;
    for (int j = 0; j < binary_strings[i].size(); j++) {
      strings.push_back(binary_strings[i][j] + "0");
      strings.push_back(binary_strings[i][j] + "1");
    }
    binary_strings.push_back(strings);
  }
}

int solve(string s) {
  int i = 0;
  // printf("Looking at string %s\n", s.c_str());
  for (i = 1; i < binary_strings.size(); i++) {
    bool flag = true;
    for (int j = 0; j < binary_strings[i - 1].size(); j++) {
      // printf("trying %s\n", binary_strings[i-1][j].c_str());
      if (s.find(binary_strings[i - 1][j]) == string::npos) {
        flag = false;
        break;
      }
    }
    if (!flag) {
      return i - 1;
    }
  }
  return i;
}

int main () {
  precompute();
  int n;
  scanf("%d", &n);
  vector<string> strings;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    strings.push_back(s);
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    string concat = strings[a - 1] + strings[b - 1];
    printf("%d\n", solve(concat));
    strings.push_back(concat);
  }
}
