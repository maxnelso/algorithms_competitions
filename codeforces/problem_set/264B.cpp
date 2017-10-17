#include <bitset>
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
#include <climits>
#include <iterator>
#include <unordered_map>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

const int MAXN = 100005;

int bp[MAXN];
int arr[MAXN];

vector<int> divisors;

int main () {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int out = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) {
      out = max(out, 1);
    }

    divisors.clear();

    int a = arr[i];
    int bval = 0;
    for (int j = 2; j * j <= a; j++) {
      if (a % j == 0) {
        divisors.push_back(j);
        bval = max(bval, bp[j] + 1);

        while (a % j == 0) {
          a /= j;
        }
      }
    }

    if (a > 1) {
      divisors.push_back(a);
      bval = max(bval, bp[a] + 1);
    }

    out = max(out, bval);
    for (int j = 0; j < divisors.size(); j++) {
      bp[divisors[j]] = max(bp[divisors[j]], bval);
    }
  }

  printf("%d", out);

}
