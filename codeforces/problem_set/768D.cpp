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
  int k, q;
  scanf("%d %d", &k, &q);

  float e = 10e-7;
  for (int i = 0; i < q; i++) {
    int p;
    scanf("%d", &p);
    float ev = 1 / k;
    //float num_of_days = ((float) k) * p - (e * k) / 2000;
    float num_of_days = ((p*k - e*k)) / 2000;
    float total_days = num_of_days * k;
    printf("%d\n", max(k, (int) ceil(total_days)));
  }
}
