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

class ORSolitaireDiv2 {
  public: int getMinimum(vector <int> numbers, int goal);
};

int ORSolitaireDiv2::getMinimum(vector <int> numbers, int goal) {
  for (int i = 0; i < numbers.size(); i++) {
    vector<bool> remove(numbers.size());
    for (int j = 0; j < numbers.size(); j++) {
      remove[j] = (numbers.size() - j - 1 < i);
    }
    do {
      int X = 0;
      for (int j = 0; j < numbers.size(); j++) {
        if ((!remove[j]) && (numbers[j] | goal) == goal) {
          X = X | numbers[j];
        }
      }
      if (X != goal) {
        return i;
      }
    } while (next_permutation(remove.begin(), remove.end()));
  }
  return numbers.size();
}

int main () {
  ORSolitaireDiv2 dummy;
  int result;

  static const int arr0[] = {1, 2, 4};
  vector<int> test0(arr0, arr0 + sizeof(arr0) / sizeof(arr0[0]));
  int test1 = 7;
  result = dummy.getMinimum(test0, test1);
  if (result == 1) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 1, result);
  }

  static const int arr2[] = {1, 2, 4, 7, 8};
  vector<int> test2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
  int test3 = 7;
  result = dummy.getMinimum(test2, test3);
  if (result == 2) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 2, result);
  }

  static const int arr4[] = {12571295, 2174218, 2015120};
  vector<int> test4(arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]));
  int test5 = 1;
  result = dummy.getMinimum(test4, test5);
  if (result == 0) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 0, result);
  }

  static const int arr6[] = {5, 2, 4, 52, 62, 9, 8, 3, 1, 11, 6};
  vector<int> test6(arr6, arr6 + sizeof(arr6) / sizeof(arr6[0]));
  int test7 = 11;
  result = dummy.getMinimum(test6, test7);
  if (result == 3) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 3, result);
  }

  static const int arr8[] = {503, 505, 152, 435, 491, 512, 1023, 355, 510, 500, 502, 255, 63, 508, 509, 511, 60, 250, 254, 346};
  vector<int> test8(arr8, arr8 + sizeof(arr8) / sizeof(arr8[0]));
  int test9 = 510;
  result = dummy.getMinimum(test8, test9);
  if (result == 5) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 5, result);
  }


}
