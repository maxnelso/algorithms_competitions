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
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    bool found = false;
    for (int j = 3; j < 10000; j++) {
      int sum_of_interior = (j - 1) * 180;
      if (j * a == (j - 2) * 180) {
        found = true;
        break;
      }
    }
    if (found) {
      if (i != n - 1) {
        printf("YES\n");
      } else {
        printf("YES");
      }
    } else {
      if (i != n - 1) {
        printf("NO\n");
      } else {
        printf("NO");
      }
    }
  }
  fflush(stdout);
}
