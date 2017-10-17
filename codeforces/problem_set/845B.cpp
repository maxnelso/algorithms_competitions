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
  string s;
  cin >> s;
  int first_sum = 0;
  int second_sum = 0;
  vector<int> first_up_diffs;
  vector<int> first_down_diffs;
  vector<int> second_up_diffs;
  vector<int> second_down_diffs;
  vector<int> second_diffs;
  for (int i = 0; i < 3; i++) {
    int a = s[i] - '0';
    first_up_diffs.push_back(9 - a);
    first_down_diffs.push_back(a);
    first_sum += a;
  }

  for (int i = 3; i < 6; i++) {
    int a = s[i] - '0';
    second_up_diffs.push_back(9 - a);
    second_down_diffs.push_back(a);
    second_sum += a;
  }

  sort(first_up_diffs.rbegin(), first_up_diffs.rend());
  sort(first_down_diffs.rbegin(), first_down_diffs.rend());
  sort(second_up_diffs.rbegin(), second_up_diffs.rend());
  sort(second_down_diffs.rbegin(), second_down_diffs.rend());
  int out = 0;
  int i = 0;
  int j = 0;
  int total_diff = abs(first_sum - second_sum);
  while (total_diff > 0) {
    if (first_sum > second_sum) {
      if (first_down_diffs[i] > second_up_diffs[j]) {
        total_diff -= first_down_diffs[i];
        i++;
      } else {
        total_diff -= second_up_diffs[j];
        j++;
      }
    } else {
      if (first_up_diffs[i] > second_down_diffs[j]) {
        total_diff -= first_up_diffs[i];
        i++;
      } else {
        total_diff -= second_down_diffs[j];
        j++;
      }

    }
    out++;
  }
  printf("%d", out);
}
