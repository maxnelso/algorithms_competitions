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
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  int ar[4] = {a, b, c, d};
  char ch[100000];
  scanf("%s", ch);
  string s(ch);
  int sum = 0;
  for (int i = 0; i < s.size(); ++i) {
    int index = s[i] - '0';
    sum += ar[index-1];
  }
  printf("%d", sum);
  setvbuf(stdout, NULL, _IONBF, 0);
}
