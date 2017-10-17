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
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      int a;
      scanf("%d", &a);
      if (a == 1) {
        printf("%d", abs(2 - i) + abs(2 - j));
        return 0;
      }
    }
  }
  fflush(stdout);
}
