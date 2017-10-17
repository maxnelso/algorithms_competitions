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
  int n, m;
  scanf("%d %d", &n, &m);
  printf("%d\n", n+m-1);
  if (m > n) {
    for (int i = 0; i < m; i++) {
      printf("1 %d\n", i + 1);
    }
    for (int i = 2; i <= n; i++) {
      printf("%d 2\n", i);
    }
  } else {
    for (int i = 0; i < n; i++) {
      printf("%d 1\n", i + 1);
    }
    for (int i = 2; i <= m; i++) {
      printf("2 %d\n", i);
    }
  }
}
