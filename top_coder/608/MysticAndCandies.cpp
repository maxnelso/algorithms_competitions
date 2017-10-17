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
using namespace std;

class MysticAndCandies {
  public: int minBoxes(int C, int X, vector <int> low, vector <int> high);
};

int MysticAndCandies::minBoxes(int C, int X, vector <int> low, vector <int> high) {
  int n = low.size();
  int H = accumulate(high.begin(), high.end(), 0);
  sort(low.rbegin(), low.rend());
  sort(high.rbegin(), high.rend());
  int a = 0;
  int b = 0;
  for (int t = 1; t < n; t++) {
    a += low[t-1];
    if (a >= X) {
      return t;
    }
    b += high[t-1];
    if (C - H + b >= X) {
      return t;
    }
  }
  return n;
}

int main () {
  MysticAndCandies dummy;
  int result;

  int test0 = 15;
  int test1 = 12;
  static const int arr2[] = {1, 2, 3, 4, 5};
  vector<int> test2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
  static const int arr3[] = {1, 2, 3, 4, 5};
  vector<int> test3(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
  result = dummy.minBoxes(test0, test1, test2, test3);
  if (result == 3) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 3, result);
  }

  int test4 = 60;
  int test5 = 8;
  static const int arr6[] = {5, 2, 3};
  vector<int> test6(arr6, arr6 + sizeof(arr6) / sizeof(arr6[0]));
  static const int arr7[] = {49, 48, 47};
  vector<int> test7(arr7, arr7 + sizeof(arr7) / sizeof(arr7[0]));
  result = dummy.minBoxes(test4, test5, test6, test7);
  if (result == 2) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 2, result);
  }

  int test8 = 58;
  int test9 = 30;
  static const int arr10[] = {3, 9, 12, 6, 15};
  vector<int> test10(arr10, arr10 + sizeof(arr10) / sizeof(arr10[0]));
  static const int arr11[] = {8, 12, 20, 8, 15};
  vector<int> test11(arr11, arr11 + sizeof(arr11) / sizeof(arr11[0]));
  result = dummy.minBoxes(test8, test9, test10, test11);
  if (result == 2) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 2, result);
  }


  int test16 = 43873566;
  int test17 = 32789748;
  static const int arr18[] = {2053198, 2175819, 4260803, 1542497, 1418952, 5000015, 1381849, 2462882, 6466891, 1827580, 6943641, 5775477};
  vector<int> test18(arr18, arr18 + sizeof(arr18) / sizeof(arr18[0]));
  static const int arr19[] = {2827461, 3726335, 5410505, 4781355, 4925909, 5621160, 7325774, 5025476, 7876037, 8072075, 6979462, 6647628};
  vector<int> test19(arr19, arr19 + sizeof(arr19) / sizeof(arr19[0]));
  result = dummy.minBoxes(test16, test17, test18, test19);
  if (result == 7) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 7, result);
  }


}
