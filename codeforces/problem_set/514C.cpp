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

// substring hash, substringhash, substring_hash
set<long long> hashes;

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  map<int, set<pair<int, int>>> memory;
  for (int i = 0; i < n; i++) {
    char c[6*(int)10e5 + 5];
    scanf("%s\n", c);
    string s(c);

    long long sum = 0;
    long long e = 1;
    for (int j = 0; j < s.size(); j++) {
      e = e * 63357 + 17;
      e %= 2305843009213693951LL;
      sum += 37 * e * (s[j] - 'a' + 1);
    }

    e = 1;
    for (int j = 0; j < s.size(); j++) {
      e = e * 63357 + 17;
      e %= 2305843009213693951LL;
      long long t = sum - 37 * e * (s[j] - 'a' + 1);
      if (s[j] != 'a') hashes.insert(t + 37 * e);
      if (s[j] != 'b') hashes.insert(t + 37 * e * 2);
      if (s[j] != 'c') hashes.insert(t + 37 * e * 3);
    }
  }


  for (int i = 0; i < m; i++) {
    char c[6*(int)10e5 + 5];
    scanf("%s\n", c);
    string s(c);

    long long sum = 0;
    long long e = 1;
    for (int j = 0; j < s.size(); j++) {
      e = e * 63357 + 17;
      e %= 2305843009213693951LL;
      sum += 37 * e * (s[j] - 'a' + 1);
    }

    if (hashes.find(sum) != hashes.end()) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

}
