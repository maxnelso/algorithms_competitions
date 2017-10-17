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
#define print_vector(a) for (int i = 0; i < a.size(); i++) { if (i == a.size() - 1) {cout << a[i];} else { cout << a[i] << " ";}}
using namespace std;

int main () {
  char c[256];
  scanf("%s", c);
  string s(c);
  char start = s[0];
  int count = 1;
  for (int i = i; i < s.size(); ++i) {
    if (s[i] == start) {
      count++;
    } else {
      start = s[i];
      count = 1;
    }
    if (count == 7) {
      printf("YES");
      fflush(stdout);
      return 0;
    }
  }
  printf("NO");
  fflush(stdout);
}
