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
  scanf("%d", &n);
  long long total_minutes = 0;
  long long total_charged = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    total_minutes += a;
    int min_cost = 0;
    int total_minutes_copy = total_minutes;
    int day_tickets = total_minutes_copy / 1440;
    min_cost += day_tickets * 120;
    total_minutes_copy -= day_tickets * 1440;

    int best_other_cost = 10000000;
    for (int j = 0; j < 100; j++) {
      
    }
  }
}
