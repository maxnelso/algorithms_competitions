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
#include <iterator>
#include <unordered_map>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int main () {
  int n;
  scanf("%d\n", &n);
  int a = 0;
  int b = 0;
  for (int i = 0; i < n; i++) {
    char c;
    scanf("%c", &c);
    if (c == 'A') {
      a++;
    } else if (c == 'D') {
      b++;
    }
  }
  if (a > b) {
    printf("Anton");
  } else if (a < b) {
    printf("Danik");
  } else {
    printf("Friendship");
  }
}
