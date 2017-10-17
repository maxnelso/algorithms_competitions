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
  int index = 0;
  string hello = "hello";
  char c[256];
  scanf("%s", c);
  string s(c);
  bool found = false;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == hello[index]) {
      index++;
      if (index == 5) {
        printf("YES");
        found = true;
        break;
      }
    }
  }
  if (!found) {
    printf("NO");
  }
  fflush(stdout);
}
