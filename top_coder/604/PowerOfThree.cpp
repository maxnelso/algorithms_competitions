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
#define print_vector(a) cout << "{"; for (int i = 0; i < a.size(); i++) { if (i == a.size() - 1) {cout << a[i];} else { cout << a[i] << ",";}} cout << "}\n";
using namespace std;

class PowerOfThree {
  public: string ableToGet(int x, int y);
};

string PowerOfThree::ableToGet(int x, int y) {
  x = abs(x);
  y = abs(y);
  while (x != 0 || y != 0) {
    if ((x % 3 == 0) && (y % 3 != 0)) {
      if (y % 3 == 2) {
        y = (y + 1) / 3;
      } else {
        y = (y - 1) / 3;
      }
      x /= 3;
    } else if ((x % 3 != 0) && (y % 3 == 0)) {
      if (x % 3 == 2) {
        x = (x + 1) / 3;
      } else {
        x = (x - 1) / 3;
      }
      y /= 3;
    } else {
      return "Impossible";
    }
  }
  return "Possible";
}

int main () {
  PowerOfThree dummy;
  string result;

  int test0 = 1;
  int test1 = 3;
  result = dummy.ableToGet(test0, test1);
  if (result == "Possible") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "Possible", result.c_str());
  }

  int test2 = 0;
  int test3 = 2;
  result = dummy.ableToGet(test2, test3);
  if (result == "Possible") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "Possible", result.c_str());
  }

  int test4 = 1;
  int test5 = 9;
  result = dummy.ableToGet(test4, test5);
  if (result == "Impossible") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "Impossible", result.c_str());
  }

  int test6 = 3;
  int test7 = 0;
  result = dummy.ableToGet(test6, test7);
  if (result == "Impossible") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "Impossible", result.c_str());
  }

  int test8 = 1;
  int test9 = 1;
  result = dummy.ableToGet(test8, test9);
  if (result == "Impossible") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "Impossible", result.c_str());
  }

  int test10 = -6890;
  int test11 = 18252;
  result = dummy.ableToGet(test10, test11);
  if (result == "Possible") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "Possible", result.c_str());
  }

  int test12 = 1000000000;
  int test13 = -1000000000;
  result = dummy.ableToGet(test12, test13);
  if (result == "Impossible") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "Impossible", result.c_str());
  }

  int test14 = 0;
  int test15 = 0;
  result = dummy.ableToGet(test14, test15);
  if (result == "Possible") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "Possible", result.c_str());
  }


}
