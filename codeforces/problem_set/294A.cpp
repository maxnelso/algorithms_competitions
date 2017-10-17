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
  setvbuf(stdout, NULL, _IONBF, 0);
  int n;
  scanf("%d", &n);
  int birds[n];
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    birds[i] = a;
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &b, &a);
    b--;
    a--;
    if (b + 1 > n) {
      birds[n-1] = 0;
      birds[n-2] += a;
    } else if (b - 1 < 0) {
      birds[1] += birds[0] - a - 1;
      birds[0] = 0;
    } else {
      birds[b-1] += a;
      birds[b+1] += birds[b] - a - 1;
      birds[b] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d\n", birds[i]);
  }
}
