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
  int cars[n];
  memset(cars, 0, n * sizeof(*cars));
  int groups[n];
  int counts[4];
  memset(cars, 0, sizeof(counts));
  for (int i = 0; i < n; ++i) {
    int group;
    scanf("%d", &group);
    groups[i] = group;
  }
  sort(groups, n + groups);
  int i = 0;
  int j = n - 1;
  int out = 0;
  while (j >= i) {
    int ele = groups[j];
    out++;
    while (j > i && ele + groups[i] <= 4) {
      ele = ele + groups[i];
      i++;
    }
    j--;
  }
  printf("%d", out);
  fflush(stdout);
}
