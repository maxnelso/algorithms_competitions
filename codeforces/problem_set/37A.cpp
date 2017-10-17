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
#define print_vector_2d(a) for (int i = 0; i < a.size(); i++) {for (int j = 0; j < a[0].size(); j++) { if (i == a.size() - 1) {cout << a[i];} else { cout << a[i] << " ";}} cout << endl; }
using namespace std;

int main () {
  int n;
  scanf("%d", &n);
  int counts[1001];
  fill(begin(counts), end(counts), 0);
  int a = 0;
  int b = 0;
  for (int i = 0; i < n; ++i) {
    int c;
    scanf("%d", &c);
    counts[c]++;
  }
  for (int i = 0; i < 1001; ++i) {
    if (counts[i] > a) {
      a = counts[i];
    }
    if (counts[i] > 0) {
      b++;
    }
  }
  printf("%d %d", a, b);
  fflush(stdout);
}
