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
  int n;
  scanf("%d", &n);
  printf("%d\n", (int) ceil( pow(n, 2) / 2.0f));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i % 2 == 0) {
        if (j % 2 == 0) {
          printf("C");
        } else {
          printf(".");
        }
      } else {
        if (j % 2 == 0) {
          printf(".");
        } else {
          printf("C");
        }
      }
    }
    printf("\n");
  }

}
