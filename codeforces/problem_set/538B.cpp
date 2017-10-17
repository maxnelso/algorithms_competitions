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

static const int MAX = 1000000;

using namespace std;

vector<string> nums;

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  char c[256];
  scanf("%s", c);
  string s(c);
  vector<string> out;
  while (true) {
    string builder = "";
    bool found = false;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] > '0') {
        s[i]--;
        builder += '1';
        found = true;
      } else {
        builder += '0';
      }
    }
    if (!found) {
      break;
    }
    out.push_back(builder);
  }

  printf("%d\n", out.size());
  for (int i = 0; i < out.size(); i++) {
    int value;
    istringstream ss(out[i]);
    ss >> value;
    printf("%d ", value);
  }

}
