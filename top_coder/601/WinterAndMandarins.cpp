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

class WinterAndMandarins {
  public: int getNumber(vector <int> bags, int K);
};

int WinterAndMandarins::getNumber(vector <int> bags, int K) {
  sort(bags.begin(), bags.end());
  int best = 1000000001;
  for (int i = 0; i < bags.size() - K + 1; i++) {
    int diff = bags[i+K - 1] - bags[i];
    best = min(best, diff);
  }
  return best;
}

int main () {
  WinterAndMandarins dummy;
  int result;

  static const int arr0[] = {10, 20, 30};
  vector<int> test0(arr0, arr0 + sizeof(arr0) / sizeof(arr0[0]));
  int test1 = 2;
  result = dummy.getNumber(test0, test1);
  if (result == 10) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 10, result);
  }

  static const int arr2[] = {4, 7, 4};
  vector<int> test2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
  int test3 = 3;
  result = dummy.getNumber(test2, test3);
  if (result == 3) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 3, result);
  }

  static const int arr4[] = {4, 1, 2, 3};
  vector<int> test4(arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]));
  int test5 = 3;
  result = dummy.getNumber(test4, test5);
  if (result == 2) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 2, result);
  }

  static const int arr6[] = {5, 4, 6, 1, 9, 4, 2, 7, 5, 6};
  vector<int> test6(arr6, arr6 + sizeof(arr6) / sizeof(arr6[0]));
  int test7 = 4;
  result = dummy.getNumber(test6, test7);
  if (result == 1) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 1, result);
  }

  static const int arr8[] = {47, 1000000000, 1, 74};
  vector<int> test8(arr8, arr8 + sizeof(arr8) / sizeof(arr8[0]));
  int test9 = 2;
  result = dummy.getNumber(test8, test9);
  if (result == 27) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 27, result);
  }


}
