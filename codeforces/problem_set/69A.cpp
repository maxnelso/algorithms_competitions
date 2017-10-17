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
  int x = 0, y = 0, z = 0;
  for (int i = 0; i < n; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    x += a;
    y += b;
    z += c;
  }
  if (x == 0 && y == 0 && z == 0) {
    printf("YES");
  } else {
    printf("NO");
  }
  fflush(stdout);
}
