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
#define print_vector_2d(a) for (int i = 0; i < a.size(); i++) {for (int j = 0; j < a[i].size(); j++) { if (i == a.size() - 1) {cout << a[i][j];} else { cout << a[i][j] << " ";}} cout << endl; }
using namespace std;

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n;
  scanf("%d", &n);
  vector<int> nums;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    nums.push_back(a);
  }
  bool even = false;
  if (nums[0] % 2 != nums[1] % 2) {
    if (nums[0] % 2 == nums[2] % 2) {
      printf("%d", 2);
    } else {
      printf("%d", 1);
    }
  } else {
    if (nums[0] % 2 == 0 && nums[1] % 2 == 0) {
      even = true;
    } else if (nums[0] % 2 != 0 && nums[1] % 2 != 0) {
      even = false;
    }
    for (int i = 0; i < n; ++i) {
      if (even) {
        if (nums[i] % 2 != 0) {
          printf("%d", i + 1);
        }
      } else {
        if (nums[i] % 2 == 0) {
          printf("%d", i + 1);
        }
      }
    }
  }
}
