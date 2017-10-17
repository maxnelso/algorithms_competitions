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

bool is_better(string a, string b) {
  int a_count = count(a.begin(), a.end(), 'r');
  int b_count = count(b.begin(), b.end(), 'r');
  for (int i = 0; i < max(a.size(), b.size()); ++i) {
    /* code */
  }
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int m;
  scanf("%d", &m);
  vector<string> words;
  for (int i = 0; i < m; ++i) {
    char c[10010];
    scanf("%s", c);
    string s(c);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    words.push_back(s);
  }

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    char c[10010];
    char d[10010];
    scanf("%s %s", c, d);
    string s(c);
    string t(d);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    transform(t.begin(), t.end(), t.begin(), ::tolower);
  }


  map<string, string*> goods;
}
