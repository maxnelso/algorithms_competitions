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
  char d[256];
  scanf("%s", d);
  string a(d);
  char e[256];
  scanf("%s", e);
  string b(e);
  char f[256];
  scanf("%s", f);
  string c(f);
  string concat = a + b;
  sort(concat.begin(), concat.end());
  sort(c.begin(), c.end());
  if (concat == c) {
    printf("YES");
  } else {
    printf("NO");
  }
  fflush(stdout);
}
