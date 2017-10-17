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
  string a(c);
  char d[256];
  scanf("%s", d);
  string b(d);
  transform(a.begin(), a.end(), a.begin(), ::tolower);
  transform(b.begin(), b.end(), b.begin(), ::tolower);
  if (a > b) {
    printf("1");
  } else if (a < b) {
    printf("-1");
  } else {
    printf("0");
  }
  fflush(stdout);
}
