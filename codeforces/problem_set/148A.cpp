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
  int k, l, m, n, d;
  scanf("%d", &k);
  scanf("%d", &l);
  scanf("%d", &m);
  scanf("%d", &n);
  scanf("%d", &d);
  int result = 0;
  for (int i = 1; i <= d; ++i) {
    if (i % k == 0 ||
        i % l == 0 ||
        i % m == 0 ||
        i % n == 0) {
      result++;
    }
  }
  printf("%d", result);
  fflush(stdout);
}
