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

vector<string> names;

void generate_names() {
  char start = 'A';
  for (int i = 0; i < 26; i++) {
    string s;
    s += (start + i);
    names.push_back(s);
  }
  for (int i = 0; i < 26; i++) {
    string s;
    s +=  'A';
    s += ('a' + i);
    names.push_back(s);
  }
}

int main () {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<string> results;
  generate_names();
  for (int i = 0; i < n - k + 1; i++) {
    char c[10];
    scanf("%s", c);
    string s(c);
    results.push_back(s);
  }
  int name_index = 0;
  vector<string> out(n);

  for (int i = 0; i < n; i++) {
    out[i] = names[name_index++];
  }
  for (int i = 0; i < n - k + 1; i++) {
    if (results[i] == "NO") {
      out[i + k - 1] = out[i];
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%s ", out[i].c_str());
  }
}
