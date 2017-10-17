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
  int k;
  scanf("%d", &k);
  string s;
  cin >> s;
  long long out = 0;
  vector<int> ones;
  long long zeroes_out = 0;
  long long consecutive_zeroes = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      ones.push_back(i);
      zeroes_out += ((consecutive_zeroes * consecutive_zeroes) + consecutive_zeroes) / 2;
      consecutive_zeroes = 0;
    }
    if (s[i] == '0') {
      consecutive_zeroes++;
    }
  }

  zeroes_out += ((consecutive_zeroes * consecutive_zeroes) + consecutive_zeroes) / 2;
  if (k == 0) {
    cout << zeroes_out;
    return 0;
  }
  int size = (int) ones.size();
  for (int i = 0; i < size - k + 1; i++) {
    long long left_zeroes = ones[i];
    if (i > 0) {
     //printf("in here x\n");
      left_zeroes = ones[i] - ones[i - 1] - 1;
    }

    //printf("start and end %d %d\n", start_one, end_one);
    long long right_zeroes = s.size() - 1 - ones[i + k - 1];
    if (i + k - 1 < ones.size() - 1) {
      //printf("in here y\n");
      right_zeroes = ones[i + k - 1 + 1] - ones[i + k - 1] - 1;
    }

    left_zeroes++;
    right_zeroes++;
    out += left_zeroes * right_zeroes;
  }

  cout << out;
}
