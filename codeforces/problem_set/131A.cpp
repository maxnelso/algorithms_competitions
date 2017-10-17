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
  bool good = false;
  bool all_upper = true;
  string fixed = "";
  for (int i = 0; i < s.size(); ++i) {
    if (i == 0) {
      if (isupper(s[i])) {
        good = true;
        fixed = fixed + (char) tolower(s[i]);
      } else {
        fixed = fixed + (char) toupper(s[i]);
      }
    } else {
      if (islower(s[i])) {
        all_upper = false;
        good = true;
      } else {
        fixed = fixed + (char) tolower(s[i]);
      }
    }
  }
  if (good && !all_upper) {
    printf("%s", s.c_str());
  } else {
    printf("%s", fixed.c_str());
  }
  fflush(stdout);
}
