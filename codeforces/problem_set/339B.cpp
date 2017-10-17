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
  int n, m;
  scanf("%d %d", &n, &m);
  int start = 0;
  long long result = 0;
  while (m > 0) {
    m--;
    int a;
    scanf("%d", &a);
    a--;
    if (start <= a) {
      result += a - start;
    } else {
      result += (n - start) + a;
    }
    start = a;
  }
  printf("%I64d", 3LL);
  fflush(stdout);
}
