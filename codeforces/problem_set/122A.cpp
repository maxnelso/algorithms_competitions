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
  if (n % 4 == 0 ||
      n % 7 == 0 ||
      n % 44 == 0 ||
      n % 47 == 0 ||
      n % 74 == 0 ||
      n % 77 == 0 ||
      n % 444 == 0 ||
      n % 447 == 0 ||
      n % 474 == 0 ||
      n % 477 == 0 ||
      n % 744 == 0 ||
      n % 747 == 0 ||
      n % 774 == 0 ||
      n % 777 == 0) {
    printf("YES");
  } else {
    printf("NO");
  }
  fflush(stdout);
}
