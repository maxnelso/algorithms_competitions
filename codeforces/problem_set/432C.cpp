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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

vector<int> primes_to(int n) {
  vector<int> primes;
  for (int i = 2; i <= n; ++i) {
    bool not_prime = false;
    for (int j = 2; j * j <= i; ++j) {
      if (n % j == 0) {
        not_prime = true;
        break;
      }
    }
    if (!not_prime) {
      primes.push_back(i);
    }
  }
  return primes;
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  vector<int> primes = primes_to(100000);
  int n;
  scanf("%d", &n);
  vector<int> nums;
  vector<int> nums_copy;
  vector<int> other;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    nums.push_back(a);
    nums_copy.push_back(a);
    other.push_back(a);
  }
  sort(nums_copy.begin(), nums_copy.end());
  vector<pair<int, int>> pairs;
  int count = 0;
  for (int i = 0; i < n; ++i) {
    int index = find(nums.begin(), nums.end(), nums_copy[i]) - nums.begin();
    while (index != i) {
      int dist = abs(index - i);
      int out_index = 0;
      for (int j = 0; j < primes.size(); ++j) {
        int swap_distance = primes[j] - 1;
        if (index + swap_distance < n && abs((index + swap_distance) - i) < dist) {
          out_index = index + swap_distance;
          dist = abs(out_index - i);
        }
        if (index - swap_distance >= 0 && abs((index - swap_distance) - i) < dist) {
          out_index = index - swap_distance;
          dist = abs(out_index - i);
        }
      }
      count ++;
      int tmp = nums[index];
      nums[index] = nums[out_index];
      nums[out_index] = tmp;
      index = out_index;
    }
  }
  printf("%d\n", count);
  nums = other;
  for (int i = 0; i < n; ++i) {
    int index = find(nums.begin(), nums.end(), nums_copy[i]) - nums.begin();
    while (index != i) {
      int dist = abs(index - i);
      int out_index = 0;
      for (int j = 0; j < primes.size(); ++j) {
        int swap_distance = primes[j] - 1;
        if (index + swap_distance < n && abs((index + swap_distance) - i) < dist) {
          out_index = index + swap_distance;
          dist = abs(out_index - i);
        }
        if (index - swap_distance >= 0 && abs((index - swap_distance) - i) < dist) {
          out_index = index - swap_distance;
          dist = abs(out_index - i);
        }
      }
      printf("%d %d\n", min(index + 1, out_index + 1), max(index + 1, out_index + 1));
      int tmp = nums[index];
      nums[index] = nums[out_index];
      nums[out_index] = tmp;
      index = out_index;
    }
  }
}
