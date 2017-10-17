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

int main () {
  vector<int> as;
  vector<int> bs;
  string s;
  cin >> s;
  for (int i = 0 ; i < s.size(); i++) {
    if (s[i] == 'a') {
      as.push_back(i);
    } else {
      bs.push_back(i);
    }
  }

  long long evens_out = 0;
  long long odds_out = 0;
  long long even_indices = 0;
  long long odd_indices = 0;
  for (int i = 0; i < bs.size(); i++) {
    odds_out++; // ourselves
    if (bs[i] % 2 == 0) {
      evens_out += odd_indices;
      odds_out += even_indices;
      even_indices++;
    } else {
      evens_out += even_indices;
      odds_out += odd_indices;
      odd_indices++;
    }
  }
  even_indices = 0;
  odd_indices = 0;
  for (int i = 0; i < as.size(); i++) {
    odds_out++; // ourselves
    if (as[i] % 2 == 0) {
      evens_out += odd_indices;
      odds_out += even_indices;
      even_indices++;
    } else {
      evens_out += even_indices;
      odds_out += odd_indices;
      odd_indices++;
    }

  }

  cout << evens_out << " " << odds_out;

}
