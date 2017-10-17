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
  int n;
  scanf("%d", &n);
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
  }
  sort(nums.begin(), nums.end());
  if (n == 1) {
    printf("-1");
    return 0;
  }
  bool constant = true;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != nums[0]) {
      constant = false;
      break;
    }
  }

  if (constant) {
    printf("1\n");
    printf("%d", nums[0]);
    return 0;
  }

  int diff = nums[1] - nums[0];
  bool arithmetic = true;
  for (int i = 0; i < nums.size() - 1; i++) {
    if (nums[i + 1] - nums[i] != diff) {
      arithmetic = false;
      break;
    }
  }

  if (arithmetic) {
    if (n == 2 && (nums[0] + nums[1]) % 2 == 0) {
      printf("3\n");
      printf("%d %d %d", nums[0] - diff, (nums[0] + nums[1]) / 2, nums[1] + diff);
      return 0;
    }
    printf("2\n");
    printf("%d %d", nums[0] - diff, nums[nums.size() - 1] + diff);
    return 0;
  }

  map<int, int> counts;
  for (int i = 0; i < nums.size() - 1; i++) {
    counts[nums[i + 1] - nums[i]]++;
  }

  if (counts.size() > 2) {
    printf("0");
    return 0;
  }

  bool seen_greater_than_one = false;
  for (auto& p : counts) {
    if (p.second > 1) {
      if (seen_greater_than_one) {
        printf("0");
        return 0;
      }
      seen_greater_than_one = true;
    }
  }

  if (!seen_greater_than_one) {
    int goodie = (counts.begin()->first);
    auto it = counts.begin();
    it++;
    int baddie = it->first;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i + 1] - nums[i] == baddie && nums[i] + goodie == nums[i + 1] - goodie) {
        printf("1\n");
        printf("%d", nums[i] + goodie);
        return 0;
      }
    }

    swap(goodie, baddie);
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i + 1] - nums[i] == baddie && nums[i] + goodie == nums[i + 1] - goodie) {
        printf("1\n");
        printf("%d", nums[i] + goodie);
        return 0;
      }
    }
  }

  int baddie = -1;
  int goodie = -1;
  for (auto& p : counts) {
    if (p.second == 1) {
      baddie = p.first;
    } else {
      goodie = p.first;
    }
  }

  for (int i = 0; i < nums.size() - 1; i++) {
    if (nums[i + 1] - nums[i] == baddie) {
      if (nums[i] + goodie == nums[i + 1] - goodie) {
        printf("1\n");
        printf("%d", nums[i] + goodie);
        return 0;
      }
    }
  }

  printf("0\n");
  return 0;
}
