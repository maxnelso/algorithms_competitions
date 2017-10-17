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

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main () {
  int a, b, n;
  scanf("%d %d %d", &a, &b, &n);
  while (true) {
    int g = gcd(a, n);
    if (g > n) {
      printf("1");
      break;
    }
    n -= g;
    g = gcd(b, n);
    if (g > n) {
      printf("0");
      break;
    }
    n -= g;
  }
  fflush(stdout);
}
