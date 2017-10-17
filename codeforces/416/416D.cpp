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
  vector<int> a;
  for (int i = 0; i < n; ++i) {
    int b;
    scanf("%d", &b);
    a.push_back(b);
  }
  int s = 0;
  int e = 0;
  int seen = 0;
  int first = 0;
  int second = 0;
  int result = 0;
  while (e < n - 1) {
    while (e < n - 1 && seen != 2) {
      if (a[e] != -1) {
        if (seen == 0) {
          first = a[e];
          seen++;
        } else {
          second = a[e];
          seen++;
        }
      }
    }
    if (seen == 2) {
      int d = second - first;
    } else {
      result++;
    }
  }
  printf("%d", max(1, result));
  fflush(stdout);
}
