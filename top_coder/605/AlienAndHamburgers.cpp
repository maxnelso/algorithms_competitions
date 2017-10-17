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

class AlienAndHamburgers {
  public: int getNumber(vector <int> type, vector <int> taste);
};

int AlienAndHamburgers::getNumber(vector <int> type, vector <int> taste) {
  map<int, vector<int> > types;
  for (int i = 0; i < type.size(); i++) {
    types[type[i]].push_back(taste[i]);
  }
  vector<int> best_sums;
  for (auto &q : types) {
    auto &p = q.second;
    sort(p.begin(), p.end(), greater<int>());
    if (p[0] < 0) {
      best_sums.push_back(p[0]);
    } else {
      int sum = 0;
      for (int i = 0; i < p.size(); i++) {
        if (p[i] < 0) {
          break;
        }
        sum += p[i];
      }
      best_sums.push_back(sum);
    }
  }
  sort(best_sums.begin(), best_sums.end(), greater<int>());
  int best = 0;
  int sum = 0;
  for (int i = 0; i < best_sums.size(); i++) {
    sum += best_sums[i];
    best = max(best, (i + 1) * sum);
  }
  return best;
}

int main () {
  AlienAndHamburgers dummy;
  int result;

  static const int arr0[] = {1, 2};
  vector<int> test0(arr0, arr0 + sizeof(arr0) / sizeof(arr0[0]));
  static const int arr1[] = {4, 7};
  vector<int> test1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
  result = dummy.getNumber(test0, test1);
  if (result == 22) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 22, result);
  }

  static const int arr2[] = {1, 1};
  vector<int> test2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
  static const int arr3[] = {-1, -1};
  vector<int> test3(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
  result = dummy.getNumber(test2, test3);
  if (result == 0) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 0, result);
  }

  static const int arr4[] = {1, 2, 3};
  vector<int> test4(arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]));
  static const int arr5[] = {7, 4, -1};
  vector<int> test5(arr5, arr5 + sizeof(arr5) / sizeof(arr5[0]));
  result = dummy.getNumber(test4, test5);
  if (result == 30) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 30, result);
  }

  static const int arr6[] = {1, 2, 3, 2, 3, 1, 3, 2, 3, 1, 1, 1};
  vector<int> test6(arr6, arr6 + sizeof(arr6) / sizeof(arr6[0]));
  static const int arr7[] = {1, 7, -2, 3, -4, -1, 3, 1, 3, -5, -1, 0};
  vector<int> test7(arr7, arr7 + sizeof(arr7) / sizeof(arr7[0]));
  result = dummy.getNumber(test6, test7);
  if (result == 54) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 54, result);
  }

  static const int arr8[] = {30, 20, 10};
  vector<int> test8(arr8, arr8 + sizeof(arr8) / sizeof(arr8[0]));
  static const int arr9[] = {100000, -100000, 100000};
  vector<int> test9(arr9, arr9 + sizeof(arr9) / sizeof(arr9[0]));
  result = dummy.getNumber(test8, test9);
  if (result == 400000) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 400000, result);
  }


}
