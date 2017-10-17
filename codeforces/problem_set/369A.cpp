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
#define print_vector_2d(a) for (int i = 0; i < a.size(); i++) {for (int j = 0; j < a[i].size(); j++) { if (i == a.size() - 1) {cout << a[i][j];} else { cout << a[i][j] << " ";}} cout << endl; }
using namespace std;

int main () {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  int a = 0;
  int b = 0;
  for (int i = 0; i < n; ++i) {
    int c;
    scanf("%d", &c);
    c == 1 ? a++ : b++;
  }
  int result = 0;
  if (a > m) {
    result += abs(m-a);
    m = 0;
  } else {
    m -= a;
  }
  if (b > (m + k)) {
    result += abs((m+k) - b);
  }
  printf("%d", result);
  fflush(stdout);
}
