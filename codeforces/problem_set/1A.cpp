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
#define print_vector(a) cout << "{"; for (int i = 0; i < a.size(); i++) { if (i == a.size() - 1) {cout << a[i];} else { cout << a[i] << ",";}} cout << "}\n";
using namespace std;

int main () {
  int n, m, a;
  scanf("%d %d %d", &n, &m, &a);
  double x = (double) ceil((double) n / a);
  double y = (double) ceil((double) m / a);
  double z = x * y;
  printf("%.0f", z);
  fflush(stdout);
}
